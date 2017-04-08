import csv
l = []
with open("output.txt", "r") as f:
    for row in f.read().split("\n"):
        l.append(row.split(' '))
with open("out.csv", "wb") as csvfile:
    writer = csv.writer(csvfile)
    writer.writerow(['Size of Input', 'Number of Comparisons in Merge Sort', 'Number of Comparisons in Randomized QuickSort', 'Number of Comparisons in Deterministic QuickSort'])
    for i in l:
        writer.writerow(i)
