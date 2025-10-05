obstacles, nr_of_found = map(int, input().split())

dangerous_obstacles = [int(input()) for _ in range(nr_of_found)]

obstacles1 = list(range(obstacles))

set1 = set(dangerous_obstacles)
set2 = set(obstacles1)

missed_obstacles = sorted(set2 - set1)

for obstacle in missed_obstacles:
    print(obstacle)

print(f"Mario got {len(set1)} of the dangerous obstacles.")

