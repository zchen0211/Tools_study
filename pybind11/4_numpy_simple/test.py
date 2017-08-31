import example
import numpy as np

# test array loading, operation and return
a = np.array(range(4)).astype(float)
b = np.array(range(4)).astype(float)

c = example.add_arrays(a, b)
print type(c), c

# test shape
print 'dimension: ', example.ndim(a)
print 'shape: ', example.shape(a)

# test index offset
print example.index_at(c, 1)

# test make array
print example.make_f_array()
print example.make_c_array()

assert example.make_c_array().flags.c_contiguous
assert not example.make_c_array().flags.f_contiguous
assert example.make_f_array().flags.f_contiguous
assert not example.make_f_array().flags.c_contiguous
