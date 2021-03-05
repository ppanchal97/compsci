def run_commands(commands):
    l = []
    for command in commands:
        unzipped_command = command.split(" ")
        if unzipped_command[0] == 'insert':
            l.insert(int(unzipped_command[1]), int(unzipped_command[2]))
        elif unzipped_command[0] == 'print':
            print(l)
        elif unzipped_command[0] == 'remove':
            l.remove(int(unzipped_command[1]))
        elif unzipped_command[0] == 'append':
            l.append(int(unzipped_command[1]))
        elif unzipped_command[0] == 'sort':
            l.sort()
        elif unzipped_command[0] == 'pop':
            l.pop()
        elif unzipped_command[0] == 'reverse':
            l.reverse()


if __name__ == '__main__':
    n = int(input())
    commands = []
    for _ in range(n):
        command = input()
        commands.append(command)
    run_commands(commands)
