#coding:utf-8

import os
import sys
import argparse

import numpy as np
import numpy.linalg as LA


def L2_normalize_numpy(x, verbose=False):
    """Row normalization
    Args:
      x: a numpy matrix of shape N*D
    Returns:
      x: L2 normalized x
    """
    sqr_row_sum = LA.norm(x, axis=1, keepdims=True)
    if verbose:
        print('There are [{}] zero-padding feature(s).'.format(len((sqr_row_sum <= 1e-7).nonzero()[0])))
    sqr_row_sum[sqr_row_sum <= 1e-7] = 1
    return x / sqr_row_sum


def main(args):
    features = np.fromfile(args.feature_path, dtype=np.float32).reshape(-1, 256)

    features = L2_normalize_numpy(features)

    np.savetxt("py_feature.txt", features, fmt="%lf")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='read feature test')
    parser.add_argument("--feature_path", metavar="feature_path", type=str, dest="feature_path", 
                        required=True)
    
    args = parser.parse_args()
    
    main(args)