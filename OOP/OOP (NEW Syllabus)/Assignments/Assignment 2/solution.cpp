#include <iostream>
using namespace std;


void extractHashtags(char Tweets[][100], int N, char**& hashtags, int& distinctCount) {
    hashtags = nullptr;      
    distinctCount = 0;       

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; Tweets[i][j] != '\0'; j++) 
        {
            if (Tweets[i][j] == '#') 
            {
                int start = j + 1; 
                char c = Tweets[i][start];

                if (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c == '_')))     //check if it is valid and shii
                {
                    int len = 0;

                    bool flag = true;
                    while (flag) 
                    {
                        char ch = Tweets[i][start + len];
                        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || (ch == '_'))
                            len++;
                        else
                            flag = false;
                    }

                    char* newTag = new char[len + 1];
                    for (int k = 0; k < len; k++)
                        newTag[k] = Tweets[i][start + k];

                    newTag[len] = '\0';

                    bool duplicate = false;
                    for (int d = 0; d < distinctCount; d++)
                    {
                        int pos = 0;
                        bool equal = true;

                        while (true)
                        {
                            char a = hashtags[d][pos];
                            char b = newTag[pos];
                            if (a == '\0' && b == '\0')
                                break;
                            if (a != b)
                            {
                                equal = false;
                                break;
                            }
                            pos++;
                        }
                        if (equal)
                        {
                            duplicate = true;
                            break;
                        }
                    }
                    if (duplicate)
                    {
                        delete[] newTag;
                    }
                    else
                    {
                        char** temp = new char* [distinctCount + 1];
                        for (int d = 0; d < distinctCount; d++)
                        {
                            temp[d] = hashtags[d];
                        }
                        temp[distinctCount] = newTag;
                        if (hashtags != nullptr)
                            delete[] hashtags;

                        hashtags = temp;
                        distinctCount++;
                    }
                    j = start + len - 1;
                }

                
            }
        }
    }
}

int main() {
    const int N = 20;  
    char Tweets[N][100] = {
        "I love programming! #coding #developer #tech",
        "Just read a great book about AI! #reading #AI #books",
        "The weather today is fantastic! #sunny #beautiful",
        "Had an amazing workout session! #fitness #health #motivation",
        "Finally, coffee time! #coffee #morning #energy",
        "Learning C programming! #coding #learning",
        "Can't wait for the weekend! #weekendvibes #excited",
        "Enjoying a relaxing day at the beach! #vacation #beach #relax",
        "New project starting today! #work #project #goals",
        "Running in the park! #fitness #nature",
        "Loving this tech conference! #tech #developer #AI",
        "Weekend vibes and relaxation time! #weekendvibes #vacation #relax",
        "Fitness goals achieved today! #fitness #health #motivation",
        "Finally got my first coffee today! #coffee #morning #energy",
        "Building a new app with C! #coding #developer",
        "Taking a walk at the beach. #beach #vacation #nature",
        "Just finished an AI course! #AI #learning #tech",
        "Work is so rewarding today! #work #project #goals",
        "A morning walk to clear my mind! #morning #fitness #nature",
        "Amazing sunny day! #sunny #beautiful #weekendvibes"
    };

    char** hashtags;   
    int distinctCount; 

    extractHashtags(Tweets, N, hashtags, distinctCount);

    cout << "Distinct Hashtags:" << endl<<endl;
    for (int i = 0; i < distinctCount; i++) 
        cout << hashtags[i] << endl;
    cout << endl;
    for (int i = 0; i < distinctCount; i++)
        delete[] hashtags[i];

    delete[] hashtags; 

    return 0;
}
