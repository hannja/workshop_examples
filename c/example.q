\p 5001
add10:`:./extend 2:(`add10;1)
dot:`:./extend 2:(`dotproduct;2)

/ try running the following commands
/add10 1 2 4.0
/add10 til 1000000
/\t dot[til 1000000;reverse til 1000000]