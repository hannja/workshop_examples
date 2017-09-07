from pyq import q
from sklearn.neighbors import KNeighborsClassifier
import numpy as np

#load the training data in q
print('loading data')
q('system"l knn.q"')
print('ready')
def build_classifier(X,y):
	neighbors=KNeighborsClassifier(n_neighbors=5,algorithm='brute',metric='euclidean')
	neighbors.fit(X,y)
	return neighbors
def py_predict(n):
	q('.debug.ST:.z.P')			#start a timer in q 
	features_train=np.array(q('flip training.features'))
	features_test=np.array(q('{x#flip testing.features}',n))
	labels_train=np.array(q('training.labels'))
	labels_test=np.array(q('{x#testing.labels}',n))
	classifier=build_classifier(features_train,labels_train)
	print('generating prediction using sklearn nearest neighbors')
	preds=classifier.predict(features_test)     	#TODO, respect N
	print('done time taken:')
	print(q('.z.P-.debug.ST'))
	return preds
def q_predict(n):
	q('.debug.ST:.z.P')
	print('generating knn prediction using kdb+')
	qpreds=q("{knn[edist2;training.features;training.labels;5;x#'testing.features]}",n)
	print('done, time taken:')
	print(q('.z.P-.debug.ST'))
	return qpreds
# use sklearn for euclidean distances
def pyq_predict(n):
	q('.debug.ST:.z.P')
	print('generating knn prediction using kdb+ and python')
	qpreds=q("{knn[pyedist2;training.features;training.labels;5;x#'testing.features]}",n)
	print('done, time taken:')
	print(q('.z.P-.debug.ST'))
	return qpreds

		
	
