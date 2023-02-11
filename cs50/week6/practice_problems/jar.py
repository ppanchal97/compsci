class Jar:
    def __init__(self, capacity):
        self.capacity = capacity
        self.size = 0

    def __str__(self):
        if self.size == 0:
            return "empty"
        else:
            return self.size * "🍪"

    def deposit(self, n):
        if self.size + n > self.capacity:
            raise ValueError
        else:
            self.size += n

    def withdraw(self, n):
        if self.size - n < 0:
            raise ValueError
        else:
            self.size -= n


def main():
    jar = Jar(10)
    print(str(jar))

    jar.deposit(2)
    print(str(jar))

    jar.withdraw(1)

    print(str(jar))

    jar.withdraw(1)

    print(str(jar))


main()
