#!/bin/python

# To run this file you need the following libraries:
# pandas - For dataframe handling
# seaborn - For plotting
# matplotlib - To control plotting done by seaborn
# 
# You can use the given requirements.txt file to install through pip with the command:
# $> python -m pip install -r requirements.txt
#
# If you don't have pip installed, you can install it on Linux-like operating systems as so:
# sudo apt install python3-pip
#
# Alternatively on IOS systems, brew should install pip with python3:
# brew install python3
#

import csv

import matplotlib.pyplot as plt

from seaborn import lineplot
from pandas import DataFrame

def parse_data(files):


    df = []

    # Open each input file and read its contents
    for f in files:
        with open(f, "r") as fp:
            reader = csv.reader(fp, delimiter=" ")
            
            # Parse each line of the file
            for line in reader:
                n = line[0]
                t = line[1]

                # Get the algorithm and order from the filename
                alg, order = f.split("_")
                order = order.split(".")[0]

                df.append((int(n), int(t), alg, order))

    # Put the data into a pandas DataFrame
    df = DataFrame(df, columns=["n", "t(sec)", "algorithm", "order"])

    return df

if __name__ == "__main__":

    df = parse_data([
        "data/bubble_random.data",
        "data/bubble_reversed.data",
        "data/bubble_sorted.data",
        "data/selection_random.data",
        "data/selection_reversed.data",
        "data/selection_sorted.data",
        "data/insertion_random.data",
        "data/insertion_reversed.data",
        "data/insertion_sorted.data"
    ])

    # Plot the data as lines
    lineplot(data=df, x="n", y="t(sec)", hue="algorithm", style="order")
    plt.show()
