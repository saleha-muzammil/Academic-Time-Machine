%will plot upto 10 labels
function plotmultipleLabels(X,L,types)

if nargin<2
    L = X(:,end);
    X = X(:,1:end-1); 
end

if nargin<3
    types = ['ms','r+','b>','c^','k.','gx','b+','c<','ks','yv'];
end

[row col] = size(L);
%for multiclass classification
if (col>1)
    [~,L] = max(L,[],2);
end

labels = unique(L);

[rows cols] = size(X);
%simple 1D plot
if (cols == 1)
    for i=1:1:length(labels)
        y = find(L == labels(i));
        plot(X(y,1),types(2*i-1:2*i));
        hold on;
    end
    hold off
    return;
end

legendStr = [];
for i=1:1:length(labels)
    y = find(L == labels(i));
    plot(X(y,1),X(y,2),types(2*i-1:2*i));
    xlabel('x_1');
    ylabel('x_2');
    
    hold on;
    legendStr = [legendStr '''class ' num2str(labels(i)) ''','];
end
legendStr(end)=[];
eval(['legend (' legendStr ')']);

hold off

