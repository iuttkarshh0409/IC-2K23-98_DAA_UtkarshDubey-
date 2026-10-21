
import csv
import os
from collections import defaultdict

import matplotlib.pyplot as plt

CSV_PATH = "data/benchmark_results.csv"
GRAPH_DIR = "graphs"

if not os.path.exists(CSV_PATH):
    raise FileNotFoundError(
        f"{CSV_PATH} not found. Run the C++ benchmark first."
    )

os.makedirs(GRAPH_DIR, exist_ok=True)

results = defaultdict(list)

with open(CSV_PATH, newline="", encoding="utf-8") as file:
    reader = csv.DictReader(file)

    required = {
        "algorithm",
        "input_size",
        "average_time_ns",
        "case",
    }

    if not required.issubset(reader.fieldnames or []):
        raise ValueError("CSV is missing required columns.")

    for row in reader:
        if row["case"] != "successful":
            continue

        results[row["algorithm"]].append(
            (
                int(row["input_size"]),
                float(row["average_time_ns"]),
            )
        )

if not results:
    raise ValueError("No benchmark results found in the CSV.")

plt.figure(figsize=(10, 6))

for algorithm, measurements in sorted(results.items()):
    measurements.sort()
    sizes = [item[0] for item in measurements]
    times = [item[1] for item in measurements]

    plt.plot(sizes, times, marker="o", label=algorithm)

plt.xlabel("Input Size (n)")
plt.ylabel("Average Search Time (nanoseconds)")
plt.title("Iterative vs Recursive Binary Search")
plt.legend()
plt.grid(True, alpha=0.3)
plt.tight_layout()

output_path = os.path.join(
    GRAPH_DIR, "binary_search_performance.png"
)
plt.savefig(output_path, dpi=200)
plt.close()

print(f"Performance graph saved to {output_path}")
