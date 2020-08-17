#coding:utf-8

import ctypes
import os
from enum import IntEnum

# Try to locate the .so file in the same directory as this file
_file = 'libsample.so'
_path = os.path.join(*(os.path.split(__file__)[:-1] + (_file,)))
_mod = ctypes.cdll.LoadLibrary(_path)

# int gcd(int, int)
gcd = _mod.gcd
gcd.argtypes = (ctypes.c_int, ctypes.c_int)
gcd.restype = ctypes.c_int

# int in_mandel(double, double, int)
in_mandel = _mod.in_mandel
in_mandel.argtypes = (ctypes.c_double, ctypes.c_double, ctypes.c_int)
in_mandel.restype = ctypes.c_int

# int divide(int, int, int *)
_divide = _mod.divide
_divide.argtypes = (ctypes.c_int, ctypes.c_int, ctypes.POINTER(ctypes.c_int))
_divide.restype = ctypes.c_int

def divide(x, y):
    rem = ctypes.c_int()
    quot = _divide(x, y, rem)

    return quot,rem.value

# void avg(double *, int n)
# Define a special type for the 'double *' argument
class DoubleArrayType:
    def from_param(self, param):
        typename = type(param).__name__
        if hasattr(self, 'from_' + typename):
            return getattr(self, 'from_' + typename)(param)
        elif isinstance(param, ctypes.Array):
            return param
        else:
            raise TypeError("Can't convert %s" % typename)

    # Cast from array.array objects
    def from_array(self, param):
        if param.typecode != 'd':
            raise TypeError('must be an array of doubles')
        ptr, _ = param.buffer_info()
        return ctypes.cast(ptr, ctypes.POINTER(ctypes.c_double))

    # Cast from lists/tuples
    def from_list(self, param):
        val = ((ctypes.c_double)*len(param))(*param)
        return val

    from_tuple = from_list

    # Cast from a numpy array
    def from_ndarray(self, param):
        return param.ctypes.data_as(ctypes.POINTER(ctypes.c_double))

DoubleArray = DoubleArrayType()
_avg = _mod.avg
_avg.argtypes = (DoubleArray, ctypes.c_int)
_avg.restype = ctypes.c_double

def avg(values):
    return _avg(values, len(values))

# struct Point { }
class Point(ctypes.Structure):
    _fields_ = [('x', ctypes.c_double),
                ('y', ctypes.c_double)]

# struct MyConfig {}
class MyConfig(ctypes.Structure):
    _fields_ = [('a', ctypes.c_int),
                ('d', ctypes.c_double),
                ('data', ctypes.c_char_p)]

# double distance(Point *, Point *)
distance = _mod.distance
distance.argtypes = (ctypes.POINTER(Point), ctypes.POINTER(Point))
distance.restype = ctypes.c_double

# void float_ptr_as_output(int n, float* output)
float_ptr_as_output = _mod.float_ptr_as_output
float_ptr_as_output.argtypes = (ctypes.c_int, ctypes.POINTER(ctypes.c_float))
float_ptr_as_output.restype = None

# void float_ptr_as_output(int n, float* output)
int64_ptr_as_output = _mod.int64_ptr_as_output
int64_ptr_as_output.argtypes = (ctypes.c_int, ctypes.POINTER(ctypes.c_longlong))
int64_ptr_as_output.restype = None

# se_engine_e enum
class se_engine_e(IntEnum):
    ENGINE_UNKNOWN = -1
    ENGINE_FLAT = 0
    ENGINE_PQ = 1
    ENGINE_DC = 2

# se_feature_cache_storage_e enum
class se_feature_cache_storage_e(IntEnum):
    CACHE_ON_NONE = 0
    CACHE_ON_MEM = 1
    CACHE_ON_DISK = 2

# SearchEngineConfig
class se_search_engine_config_t(ctypes.Structure):
    _fields_ = [
        ('max_db_size', ctypes.c_ulonglong),
        ('feature_dim', ctypes.c_int),
        ('se_engine_e', ctypes.c_int),
        ('de_model', ctypes.c_char_p),
        ('cache_storage', ctypes.c_int)
    ]
