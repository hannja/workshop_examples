# KNN
K nearest neighbors example using pyq, uses the same dataset as the recent whitepaper
examples allow us to run
1. pure python implementation (retrieving data from q and using sklearn with a brute force algorithm)
2. pure q implementation
3. pyq implementation using sklearn distance metric instead of q matrix multiply.

There is a shared lib required by q for the ximin function (indices of x smallest elements in y)
To build

`make xminmax` 

Then to run the examples

`pyq -i knn_comp.py`

```python
py_preds=py_predict(1000)
q_preds=q_predict(1000)
pyq_preds=pyq_predict(1000)
```

## Windows

To run on windows you must have cl avalilable to compile the shared library and install pyq for windows.  With both of these you can run


`wbuild.bat`

then 

`q python.q -i@ knn_comp.py`

(to get python REPL in pyq on windows you currently have to enter ^Z then enter when pyq starts)

Only a brute force algorithm is implemented so far
