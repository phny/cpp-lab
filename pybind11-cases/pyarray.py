#coding:utf-8

import pyarray as pya

import numpy as np
from time import time
import argparse

def main(args):
    feature_path = args.feature_path
    arr = np.fromfile(feature_path, dtype=np.float32).reshape(-1, 256)
    print("finished load feature: {}, shape: {}".format(feature_path, arr.shape))

    t1 = time()
    pya.test_opaque_array(arr)
    t2 = time()
    print("test_opaque_array time consume: {}".format(t2 - t1))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='test')
    parser.add_argument("--feature_path", metavar="feature_path", type=str, dest="feature_path", 
                        required=True)
    
    args = parser.parse_args()

    main(args)