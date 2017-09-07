train:(17#"J";csv)0:`pendigits.tra
training.features:16#train
training.labels:last train
test:(17#"J";csv)0:`pendigits.tes
testing.features:16#test
testing.labels:last test

/ requires xminmax lib, if you don't have it you can replace 
/ ximin with {x#iasc y} which is takes as long as kdb+ sort of y (we have to do this for each query point)
/ xmin is O(n log k) (though each of the log k operations is more expensive) 
/ x mininum function
/xmin:`:./xminmax 2:(`xmin;2)
/ x min indices
ximin:(`$"./",string[.z.o],"/xminmax") 2:(`ximin;2);
/ simple mode (voting used amongst k neighbors)
mode:{u?max u:?[([]x);();`x;(count;`i)]}

/ df dyadic distance function, features n length list of features where n is number of features
/ labels m length list of class labels where there are m data points in training set
/ k kNN
/ data testing input same shape as features
/ returns l class labels, 1 per data point in the testing set
/ VERSION 1, exhaustive search version, no optimisation calculates distance for every point in training
/ set for each prediction (i.e. awful)
/ exhaustive search version
knn:{[df;features;labels;k;data](mode labels ximin[k]@)each df[features;data]}
/ x assumed to be n length list of lists where n is number of features
/ y same 
/ returns distances from each x for each y
edisto:{x{sum u*u:x-y}/:flip y}
/ euclidean distance calculated using dot(x,x)+dot(y,y)-2*dot(x,y) last one only one which takes much time
edist2:{(wsum[y;y]-2*flip[y:"f"$y]$x)+\:x wsum x:"f"$x}

/
/ sklearn distance metrics are fast for small arrays, define a euclidean distance function here if running under python
p)from pyq import K
p)from sklearn.metrics import euclidean_distances
p)def edist2(x,y):
	return K(euclidean_distances(x,y,squared=True))
p)q.py_edist2=edist2

pyedist2:{flip py_edist2 flip each (x;y)}
/ manhattan distance (not optimised)
mdist:{x{sum abs x-y}/:flip y}

/ neareast neighbor predictions
/\t preds:enlist[1]!enlist knn[edist2;training.features;training.labels;1;testing.features]
/\t preds[3]:knn[edist2;training.features;training.labels;3;testing.features]
/\t preds[5]:knn[edist2;training.features;training.labels;5;testing.features]

accuracy:{select accurary:avg pred=actual by class:actual from ([]pred:x;actual:y)}

/show accuracy[preds 1;testing.labels]
/show accuracy[preds 3;testing.labels]
/show accuracy[preds 5;testing.labels]


