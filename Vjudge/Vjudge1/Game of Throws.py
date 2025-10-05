n, k = map(int, input().split())
commands = input().split()
processed_commands = []
i = 0

while i < len(commands):
    cmd = commands[i]
    if cmd == "undo":
        elements_removed = int(commands[i + 1])
        processed_commands = processed_commands[:-elements_removed]
        i += 2
    else:
        processed_commands.append(int(cmd)) 
        i += 1

final_position = sum(processed_commands) % n

if final_position < 0:
    final_position += n

print(final_position)

