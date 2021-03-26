import sys

sys.path.append("../build")

import certfhepy

context = certfhepy.Context(1247, 16)

sk = certfhepy.SecretKey(context)

pt0 = certfhepy.Plaintext(0)
pt1 = certfhepy.Plaintext(1)

ct0 = sk.encrypt(pt0)
ct1 = sk.encrypt(pt1)

added = ct0 + ct1
multi = ct0 * ct1


dec_sum = sk.decrypt(added)
dec_mul = sk.decrypt(multi)

print("Sum={0}; Multi={1}".format(dec_sum.getValue(), dec_mul.getValue()))
