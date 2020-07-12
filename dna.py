import csv
import sys
import re
import cs50
from collections import OrderedDict

if len(sys.argv) > 3 or len(sys.argv) < 2:
    print("Error")
    exit(1)

with open(sys.argv[1], 'r') as d:
    database = csv.DictReader(d, delimiter=',')
    dat_dict = {}
    big_list = []
    for line in database:
        dat_dict.update(line)
        m = dat_dict.copy()
        big_list.append(m)

s = open(sys.argv[2], 'r')
sequence = s.read()

def counting(x, simple_list):
    result_list = iter(simple_list)
    count = 0
    max_count = 0
    for m in simple_list:
        i = next(result_list)
        if i != x:
            count = 0
            continue
        elif i == x:
            count += 1
            if max_count < count:
                max_count = count
            continue
    return max_count

a = 0

if str(sys.argv[1]) == "databases/small.csv":
    result_small = re.split("(AGATC|AATG|TATC)", sequence)
    while "" in result_small:
        result_small.remove("")
    for i in range(len(big_list)):
        if(big_list[i]["AGATC"] == str(counting("AGATC", result_small)) and
            big_list[i]["AATG"] == str(counting("AATG", result_small)) and
            big_list[i]["TATC"] == str(counting("TATC", result_small))):
                print(big_list[i]["name"])
                a += 1
        else:
            continue
elif str(sys.argv[1]) == "databases/large.csv":
    result_large = re.split("AGATC|TTTTTTCT|AATG|TCTAG|GATA|TATC|GAAA|TCTG", sequence)
    while "" in result_large:
        result_large.remove("")
    for i in range(len(big_list)):
        if(big_list[i]["AGATC"] == str(counting("AGATC", result_large)) and
            big_list[i]["TTTTTTCT"] == str(counting("TTTTTTCT", result_large)) and
            big_list[i]["AATG"] == str(counting("AATG", result_large)) and
            big_list[i]["TCTAG"] == str(counting("TCTAG", result_large)) and
            big_list[i]["GATA"] == str(counting("GATA", result_large))and
            big_list[i]["TATC"] == str(counting("TATC", result_large)) and
            big_list[i]["GAAA"] == str(counting("GAAA", result_large)) and
            big_list[i]["TCTG"] == str(counting("TCTG", result_large))):
                print(big_list[i]["name"])
                a += 1
        else:
            continue

if a == 0:
    print("No Match")

s.close()
d.close()

exit(0)
