#coding:utf-8

import struct
from ctypes import *

import sample as sa

def test():
    # MyConfig test
    my_config = sa.MyConfig()
    my_config.a = 100
    my_config.d = 10.9
    data = create_string_buffer(b'my config test')
    my_config.data = data.raw

    # float_ptr_as_output test
    output_result = create_string_buffer(10 * 4)
    sa.float_ptr_as_output(10, cast(pointer(output_result), POINTER(c_float)))
    ret_bytes = output_result.raw
    for  i in range(10):
        r = struct.unpack('f', ret_bytes[i*4:(i+1)*4])[0]
        print(r)

    # int64_ptr_as_output test
    output_result = create_string_buffer(10 * 8)
    sa.int64_ptr_as_output(10, cast(pointer(output_result), POINTER(c_longlong)))
    ret_bytes = output_result.raw
    for  i in range(10):
        r = struct.unpack('q', ret_bytes[i*8:(i+1)*8])[0]
        print(r)

    # enum test
    print(sa.se_engine_e.ENGINE_FLAT)

    # se_search_engine_config_t
    c = sa.se_search_engine_config_t()
    c.max_db_size = -1
    c.feature_dim = 256
    # c.dc_model = create_string_buffer(b'dc_model')
    c.dc_model = "create_string_buffer(b'dc_model')"
    c.cache_storage = sa.se_engine_e.ENGINE_FLAT

    print(c.cache_storage)
    print(c.dc_model)


if __name__ == "__main__":
    test()
    