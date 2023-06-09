function writeKaggle(x,y,Name,writeText)
%%% write the data x and corresponding labels y in a file named Name
%%% if writeText is true then it will also write a corresponding text file
%%% if x or y is [] then the corresponding file will not get generated
%%% if you have your predictions then you can generate a sample submission
%%% using   writeKaggle([],predictions,'mysolution',false)
%%% Mehreen Saeed
%%% SPRL fall 2016

if nargin < 4
    writeText = true;
end

if length(x)
    writeIt(x,Name,'feat',writeText);
end
if length(y)
    writeIt(y,[Name 'Labels'],'label',writeText);
end

function writeIt(x,Name,label,writeText)

fileName = [Name '.csv'];
[row col] = size(x);

%generate the header
h={};
for i=1:col
    h = {h{:} [label num2str(i)]};
end

file = fopen(fileName,'w');
fprintf(file,'Id');
fprintf(file,',%s',h{:});
fprintf(file,'\r\n');

dat = [[1:row]' x];

dlmwrite(fileName,dat,'-append');

if writeText
    fileName = [Name '.txt'];
    save(fileName,'x','-ascii');
end    