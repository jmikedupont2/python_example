test: pip
	python3 ./exercise.py
clean :
	rm -rf python_example.egg-info build
	pip3 uninstall -y example-python

deps: /testing/pybind11/include/pybind11/pybind11.h

#      /testing/pybind11/include/pybind11/pybind11.h

pip : deps clean
	python3 ./setup.py install
