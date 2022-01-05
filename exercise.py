import python_example

print ("CONSTR1")
d = python_example.Foo()

print ("CONSTR2")
d2 = python_example.Foo()

print(type(d))
print ("MUNGE3")
d23 = python_example.Foo.munge3(d)

print ("MUNGE")
d23 = d.munge()

print ("MUNGE2")
d24 = d.munge2(d2)
