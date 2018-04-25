RS_graph.pdf : advection.txt
	python RS_graph.py

advection.txt:
	c++ RS_advection.cpp -o temp.rs
	./temp.rs > advection.txt
