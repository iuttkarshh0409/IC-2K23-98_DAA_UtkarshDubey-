
import csv
import os
import sys
from collections import defaultdict

import matplotlib.pyplot as plt

RESULTS_FILE = "data/results.csv"
GRAPH_DIR = "graphs"

def main():
    if not os.path.exists(RESULTS_FILE):
        print(f"Error: {RESULTS_FILE} not found.")
        print("Run benchmark.exe from the experiment directory first.")
        sys.exit(1)

    results = defaultdict(list)

    with open(RESULTS_FILE, "r", newline="", encoding="utf-8") as file:
        reader = csv.DictReader(file)

        required = {
            "InputSize",
            "Algorithm",
            "AverageTimeMicroseconds",
            "AllRunsSorted",
        }

        if not required.issubset(reader.fieldnames or []):
            print("Error: CSV is missing required columns.")
            sys.exit(1)

        for row in reader:
            if row["AllRunsSorted"] != "PASS":
                print("Error: benchmark contains failed sorting results.")
                sys.exit(1)

            size = int(row["InputSize"])
            algorithm = row["Algorithm"]
            elapsed = float(row["AverageTimeMicroseconds"])

            results[algorithm].append((size, elapsed))

    if not results:
        print("Error: no benchmark results found.")
        sys.exit(1)

    os.makedirs(GRAPH_DIR, exist_ok=True)

    plt.figure(figsize=(10, 6))

    for algorithm, measurements in sorted(results.items()):
        measurements.sort()
        sizes = [item[0] for item in measurements]
        times = [item[1] for item in measurements]

        plt.plot(sizes, times, marker="o", label=algorithm)

    plt.title("Sorting Algorithm Performance Comparison")
    plt.xlabel("Input Size (n)")
    plt.ylabel("Average Execution Time (microseconds)")
    plt.grid(True)
    plt.legend()
    plt.tight_layout()
    plt.savefig(
        os.path.join(GRAPH_DIR, "sorting_performance.png"),
        dpi=300,
    )
    plt.close()

    print("Performance graph generated:")
    print(f"  {GRAPH_DIR}/sorting_performance.png")

if __name__ == "__main__":
    main()
