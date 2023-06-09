from azureml import Workspace
from azureml import DataTypeIds
import pandas as pd
import numpy as np
import datetime as dt

class MyFrame(object):
    """A dataset with unprocessed data. MyFrames have the
    following properties:

    Attributes:
        inputfile: A csv file's name consisting of the unprocessed data.
        frame: A dataframe consisting of data ready to be cleaned.
        ws: The azure machine learning studio 
    
    Methods: (To be carried out in exact order)
        cleaning ends : Cleans excess spaces from both sides of a phrase
        deduplication : Cleans duplicate rows
        find age : Calculates age of a customer
        standardize dob : Rewrites date correctly
        standardize gender : Rewrites gender correctly
        state fullname : Gives us the full name of a customer
        parse address : Divides the address into parts and cleans invalid values
        clear old values : Rids of the old data
        ouput clean data : Saves clean data to file
        sum of ages per city : Saves summary of ages per city into a file
        count of customers per age : Saves counts of customers per age into a file
    """

    def __init__(self, inputfile = 'StaggingDataCSV.csv',errorfile = 'errorfile.csv'):
        """Return a MyFrame object whose input file is *inputfile* and data 
        frame is *frame*."""
        self.inputfile = inputfile
        self.errorfile = errorfile
        self.runtimelog = pd.DataFrame({'DateTimeAccount':[],'ErrorMessage':[]})
        pd.set_option('precision', 0)
        self.ws = Workspace()
        try:
            ds = self.ws.datasets[inputfile]
            self.frame = ds.to_dataframe()
        except:
            self.runtimelog = self.runtimelog.append({'DateTimeAccount':dt.datetime.now(),'ErrorMessage':'Could not open input file'},ignore_index=True)
            print('Could not open input file')
            self.frame = pd.DataFrame({'ID':pd.Series([], dtype='int'),'Fname':pd.Series([], dtype='str'),'Lname':pd.Series([], dtype='str'),'Gender':pd.Series([], dtype='str'),'Address':pd.Series([], dtype='str'),'DOB':pd.Series([], dtype='str')})
        self.frame
                 
    def cleaning_ends(self):
        """Cleans the spaces at the ends of
        any phrase."""
        for i in self.frame:
            if ((len(self.frame[i]) > 0) and (type(self.frame[i][0]) is str)):
                self.frame[i] = self.frame[i].str.strip(' \t\r\n')
        #self.frame
                 
    def deduplication(self):
        """Deletes customers that have match on all values except
        thier ID."""
        tempframe = self.frame
        if 'ID' in tempframe:
            tempframe = tempframe.rename(columns={"ID": "RemovedID"})
        self.frame = self.frame.drop_duplicates(subset=set(self.frame) - set(['ID'])) #subset=['Fname','Lname','Gender','Address','DOB'])
        self.frame = self.frame.reset_index(drop = True)
        if 'RemovedID' in tempframe:
            tempframe = tempframe[~tempframe['RemovedID'].isin(self.frame['ID'])]
        errorframe = tempframe.merge(self.frame,on=list(set(self.frame) - set(['ID','RemovedID'])))
        errorframe['TimeLog'] = dt.datetime.now()
        if 'ID' in errorframe:
            errorframe = errorframe.rename(index=str,columns={"ID": "OriginalID"})
        try:
            dataset = self.ws.datasets.add_from_raw_data(raw_data=errorframe.to_csv(),data_type_id=DataTypeIds.GenericCSV,name=self.errorfile,description='Clean Data')
        except:
            self.runtimelog = self.runtimelog.append({'DateTimeAccount':dt.datetime.now(),'ErrorMessage':'The error log file could not be created'},ignore_index=True)
            print ('The error log file could not be created')
        #errorframe
        #self.frame
                 
    def find_age(self):
        """Calculates age in years of a
        customer"""
        if 'DOB' not in self.frame:
            self.runtimelog = self.runtimelog.append({'DateTimeAccount':dt.datetime.now(),'ErrorMessage':'Could not find date of birth and hence unable to compute age'},ignore_index=True)
            print('Could not find date of birth and hence unable to compute age')
        else:
            self.frame['DOB'] = pd.to_datetime(self.frame['DOB'], errors='coerce')
            dayoftheyear = dt.datetime.now() - dt.datetime(dt.datetime.now().year,1,1)
            self.frame['Age'] = self.frame['DOB']
            self.frame['Age'] = self.frame['Age'].apply(lambda x: np.nan if (type(x) is pd.tslib.NaTType) else int(dt.datetime.now().year - x.year) if (dayoftheyear > (x - dt.datetime(int(x.year),1,1))) else int(dt.datetime.now().year - x.year - 1) ) 
        #self.frame
                 
    def standardize_dob(self):
        """Formats date of birth into a display of ordinal day of the month along with month name and the complete
        year"""
        if 'DOB' not in self.frame:
            self.runtimelog = self.runtimelog.append({'DateTimeAccount':dt.datetime.now(),'ErrorMessage':'Could not find date of birth and hence unable to standardize it'},ignore_index=True)
            print('Could not find date of birth and hence unable to standardize it')
        else:
            self.frame['DOB'] = pd.to_datetime(self.frame['DOB'], errors='coerce')
            rest = self.frame['DOB'].dt.strftime(' %B, %Y')
            self.frame['DOB'] = self.frame['DOB'].dt.strftime('%-d')
            ordinal = {'1':'st','2':'nd','3':'rd'}
            self.frame['DOB'] = self.frame['DOB'].apply(lambda x: (x + ordinal.get(x[-1],'th')) if (len(x) != 2 or x[-2] != '1') else (x+'th')).replace('NaTth',np.nan)
            self.frame['DOB'] = self.frame['DOB'] + rest
        #self.frame
                 
    def standardize_gender(self):
        """Sets gender to either male or
        female"""
        if 'DOB' not in self.frame:
            self.runtimelog = self.runtimelog.append({'DateTimeAccount':dt.datetime.now(),'ErrorMessage':'Could not find gender and hence unable to standardize it'},ignore_index=True)
            print('Could not find gender and hence unable to standardize it')
        else:
            gender = {'m':'male','f':'female','1':'male','0':'female','Male':'male','Female':'female','M':'male','F':'female'}
            g = list(gender.keys())+['male','female']
            errorframe = self.frame[~(self.frame['Gender'].isin(g))]
            errorframe['TimeLog'] = dt.datetime.now()
            self.frame = self.frame[(self.frame['Gender'].isin(g))]
            self.frame = self.frame.replace({'Gender':gender})
            self.frame = self.frame.reset_index(drop = True)
            if 'ID' in errorframe:
                errorframe = errorframe.rename(index=str,columns={"ID": "ID of errorsome Gender"})
            try:
                dataset = self.ws.datasets.add_from_raw_data(raw_data=errorframe.to_csv(),data_type_id=DataTypeIds.GenericCSV,name=self.errorfile,description='Clean Data')
            except:
                self.runtimelog = self.runtimelog.append({'DateTimeAccount':dt.datetime.now(),'ErrorMessage':'The error log file could not be created'},ignore_index=True)
                print ('The error log file could not be created')
        #self.frame 
                 
    def state_fullname(self):
        """Delivers the full name of the 
        customer"""
        if 'Fname' not in self.frame and 'Lname' not in self.frame:
                self.frame['FullName'] = np.nan
                self.runtimelog = self.runtimelog.append({'DateTimeAccount':dt.datetime.now(),'ErrorMessage':'Could not find correct full names because first names and last names are not given'},ignore_index=True)
                print('Could not find correct full names because first names and last names are not given')
        else:
            if 'Fname' not in self.frame:
                self.frame['Fname'] = ''
                self.runtimelog = self.runtimelog.append({'DateTimeAccount':dt.datetime.now(),'ErrorMessage':'Could not find correct full names because first names are not given'},ignore_index=True)
                print('Could not find correct full names because first names are not given')
            elif 'Lname' not in self.frame:
                self.frame['Lname'] = ''
                self.runtimelog = self.runtimelog.append({'DateTimeAccount':dt.datetime.now(),'ErrorMessage':'Could not find correct full names because last names are not given'},ignore_index=True)
                print('Could not find correct full names because last names are not given')
            firsthalf = self.frame['Fname']
            firsthalf.apply(lambda x: '' if type(x) is not str else x)
            secondhalf = self.frame['Lname']
            secondhalf.apply(lambda x: '' if type(x) is not str else x)
            self.frame['FullName'] = firsthalf + ' ' + secondhalf
            for i in range(len(self.frame['FullName'])):
                if(type(self.frame['Fname'][i]) is not str and type(self.frame['Lname'] is not str)):
                    self.frame.at[self.frame['ID'][i], 'FullName'] = np.nan
            self.frame['FullName'] = self.frame['FullName'].str.strip(' ')
        #self.frame

    def parse_address(self):
        """Separates Street, Colony and City where they can be found in the
        data"""
        if 'Address' not in self.frame:
            self.runtimelog = self.runtimelog.append({'DateTimeAccount':dt.datetime.now(),'ErrorMessage':'Could not find any address to parse'},ignore_index=True)
            print('Could not find any address to parse')
        else:
            self.frame = self.frame[pd.notnull(self.frame['Address'])]
            self.frame = self.frame.reset_index(drop = True)
            self.frame['Address'] = self.frame['Address'].apply(lambda x: ' '.join(x.split(' ')) if x is str else x)
            self.frame['Address'] = self.frame['Address'].str.lower()
            self.frame['Street'] = self.frame['Address']
            self.frame['Colony'] = self.frame['Address']
            self.frame['City'] = self.frame['Address']
            self.frame['Street'] = self.frame['Street'].apply(lambda x: (( x.split(',')[0].strip(' \t\n\r') if 'street' in x.split(',')[0] else np.nan ) if ',' in x else x.split(' ')[0].strip(' \t\n\r') if 'street' in x.split(' ')[0] else np.nan) if type(x) is str else np.nan) 
            colonyat = 0
            for i in range(len(self.frame['Colony'])):
                if pd.notnull(self.frame['Street'][i]):
                    colonyat = 1
                else:
                    colonyat = 0
                if type(self.frame['Colony'][i]) is str:
                    if ',' in self.frame['Colony'][i]:
                        if len(self.frame['Colony'][i].split(',')) > colonyat:
                            if 'colony' in self.frame['Colony'][i].split(',')[colonyat]:
                                self.frame.at[i,'Colony'] = self.frame['Colony'][i].split(',')[colonyat].strip(' \t\n\r')
                                if len(self.frame['City'][i].split(',')) > (colonyat+1):
                                    self.frame.at[i,'City'] = self.frame['City'][i].split(',')[colonyat+1].strip(' \t\n\r')
                                else: 
                                    self.frame.at[i,'City'] = np.nan
                            else:
                                self.frame.at[i,'Colony'] = np.nan
                                self.frame.at[i,'City'] = self.frame['City'][i].split(',')[colonyat].strip(' \t\n\r')
                        else:
                            self.frame.at[i,'Colony'] = np.nan
                            self.frame.at[i,'City'] = np.nan                    
                    else:
                        if len(self.frame['Colony'][i].split(',')) > colonyat:
                            if 'colony' in self.frame['Colony'][i].split(' ')[0]:
                                self.frame.at[i,'Colony'] = self.frame['Colony'][i].split(' ')[colonyat].strip(' \t\n\r')
                                if len(self.frame['City'][i].split(' ')) > (colonyat+1):
                                    self.frame.at[i,'City'] = self.frame['City'][i].split(' ')[colonyat+1].strip(' \t\n\r')
                                else: 
                                    self.frame.at[i,'City'] = np.nan
                            else:
                                self.frame.at[i,'Colony'] = np.nan
                                self.frame.at[i,'City'] = self.frame['City'][i].split(' ')[colonyat].strip(' \t\n\r')
                        else:
                            self.frame.at[i,'Colony'] = np.nan
                            self.frame.at[i,'City'] = np.nan
                else:
                    self.frame.at[i,'Colony'] = np.nan 
                    self.frame.at[i,'City'] = np.nan
            self.frame = self.frame[pd.notnull(self.frame['City'])]
            errorframe = self.frame[pd.isnull(self.frame['City'])]
            errorframe['TimeLog'] = dt.datetime.now()
            self.frame = self.frame.reset_index(drop = True)
            self.frame['Street'] = self.frame['Street'].str.title()
            self.frame['Colony'] = self.frame['Colony'].str.title()
            self.frame['City'] = self.frame['City'].str.title()
            if 'ID' in errorframe:
                errorframe = errorframe.rename(index=str,columns={"ID": "ID of misplaced city"})
            try:
                dataset = self.ws.datasets.add_from_raw_data(raw_data=errorframe.to_csv(),data_type_id=DataTypeIds.GenericCSV,name=self.errorfile,description='Clean Data')
            except:
                self.runtimelog = self.runtimelog.append({'DateTimeAccount':dt.datetime.now(),'ErrorMessage':'The error log file could not be created'},ignore_index=True)
                print ('The error log file could not be created')
        #self.frame
                 
    def clear_old_values(self):
        """Rids the data of unneeded 
        values"""
        self.frame = self.frame.drop(set(self.frame)-set(['ID','FullName','Street','Colony','City','Gender','DOB','Age']), axis=1)
        #self.frame
    
    def ouput_clean_data(self, outputfile):
        """Outputs freshly processed data in a csv file named *outputfile* which should not exist
        beforehand"""
        try:
            dataset = self.ws.datasets.add_from_raw_data(raw_data=self.frame.to_csv(),data_type_id=DataTypeIds.GenericCSV,name=outputfile,description='Clean Data')
        except:
            self.runtimelog = self.runtimelog.append({'DateTimeAccount':dt.datetime.now(),'ErrorMessage':'The output file could not be created'},ignore_index=True)
            print ('The output file could not be created')
        #self.frame
    
    def sum_of_ages_per_city(self, outputfile):
        """Outputs freshly summarized age data in a csv file named *outputfile* which should not exist
        beforehand"""
        if 'City' not in self.frame:
            self.runtimelog = self.runtimelog.append({'DateTimeAccount':dt.datetime.now(),'ErrorMessage':'Could not find cities by which to group by'},ignore_index=True)
            print('Could not find cities by which to group by')
        elif 'Age' not in self.frame:
            self.runtimelog = self.runtimelog.append({'DateTimeAccount':dt.datetime.now(),'ErrorMessage':'Could not find ages by which are to b summarized'},ignore_index=True)
            print('Could not find ages by which are to b summarized')
        else:
            grouped = self.frame.groupby(['City'])
            percitysumofages = pd.DataFrame(grouped['Age'].sum())
            try:
                dataset = self.ws.datasets.add_from_raw_data(raw_data=percitysumofages.to_csv(),data_type_id=DataTypeIds.GenericCSV,name=outputfile,description='Clean Data')
            except:
                self.runtimelog = self.runtimelog.append({'DateTimeAccount':dt.datetime.now(),'ErrorMessage':'The summary of ages per city could not be saved'},ignore_index=True)
                print ('The summary of ages per city could not be saved')
        #percitysumofages
        
    def count_of_customers_per_age(self, outputfile):
        """Outputs freshly summarized total customers data in a csv file named *outputfile* which should not exist
        beforehand"""
        if 'Age' not in self.frame:
            self.runtimelog = self.runtimelog.append({'DateTimeAccount':dt.datetime.now(),'ErrorMessage':'Could not find ages by which to group by'},ignore_index=True)
            print('Could not find ages by which to group by')
        elif 'ID' not in self.frame:
            self.runtimelog = self.runtimelog.append({'DateTimeAccount':dt.datetime.now(),'ErrorMessage':'Could not find count of unique customers'},ignore_index=True)
            print('Could not find count of unique customers')
        else:
            group = self.frame.groupby(['Age'])
            peragecountofcustomers = pd.DataFrame(group['ID'].count())
            try:
                dataset = self.ws.datasets.add_from_raw_data(raw_data=peragecountofcustomers.to_csv(),data_type_id=DataTypeIds.GenericCSV,name=outputfile,description='Clean Data')
            except:
                self.runtimelog = self.runtimelog.append({'DateTimeAccount':dt.datetime.now(),'ErrorMessage':'The summary of customers per age could not be saved'},ignore_index=True)
                print ('The summary of customers per age could not be saved')
            #peragecountofcustomers

    def output_runtimelog(self, outputfile = 'runtimelog.csv'):
        """Outputs freshly processed data in a csv file named *outputfile* which should not exist
        beforehand"""
        try:
            dataset = self.ws.datasets.add_from_raw_data(raw_data=self.runtimelog.to_csv(),data_type_id=DataTypeIds.GenericCSV,name=outputfile,description='Clean Data')
        except:
            self.runtimelog = self.runtimelog.append({'DateTimeAccount':dt.datetime.now(),'ErrorMessage':'The runtime log file could not be created'},ignore_index=True)
            print ('The runtime log file could not be created')
        #self.frame
            
mf = MyFrame('StaggingDataCSVfake.csv','error1.csv')
mf.cleaning_ends()
mf.deduplication()
mf.find_age()
mf.standardize_dob()
mf.errorfile = 'error2.csv'
mf.standardize_gender()
mf.state_fullname()
mf.errorfile = 'error3.csv'
mf.parse_address()
mf.clear_old_values()
mf.ouput_clean_data("output.csv")
mf.sum_of_ages_per_city("sumofagespercity.csv")
mf.count_of_customers_per_age("countofcustomersperage.csv")
mf.output_runtimelog()


### This solution is submission of a student