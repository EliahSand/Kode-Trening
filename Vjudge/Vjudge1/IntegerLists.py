from sys import stdin

def main():
    for _ in range(int(next(stdin))):
        is_normal = True
        remove_from_start = 0
        remove_from_end = 0

        for action in next(stdin):
            if action == "R":
                is_normal = not is_normal
            elif action == "\n":
                break
            elif is_normal:
                remove_from_start += 1
            else:
                remove_from_end += 1

        length_of_list = int(next(stdin))

        if remove_from_start + remove_from_end > length_of_list:
            print("error")
            next(stdin)
            continue
        elif remove_from_start + remove_from_end == length_of_list:
            print("[]")
            next(stdin)
            continue

        elements = next(stdin)[1:-2].split(",", length_of_list - remove_from_end)

        if remove_from_end > 0:
            elements.pop()

        if remove_from_start > 0:
            elements = elements[remove_from_start:]

        if not is_normal:
            elements = reversed(elements)

        print("[", ",".join(elements), "]", sep="")

if __name__ == "__main__":
    main()

