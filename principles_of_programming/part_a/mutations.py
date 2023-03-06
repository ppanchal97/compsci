class AuthorizationService:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    allowed_security_groups = ["admin", "owner", "root"]

    def get_current_user_group(self):
        return "reader"

    # Return an alias to the internal list of authorized user groups
    def get_allowed_users_unsafe(self):
        return self.allowed_security_groups

    # Return a shallow copy of the internal list of authorized user groups
    def get_allowed_users_safe(self):
        return self.allowed_security_groups

    def validate_user(self):
        if self.get_current_user_group() in self.allowed_security_groups:
            print("Access validated")
        else:
            print(
                f"Unauthorized access. Current role is {self.get_current_user_group()}, only {' '.join(self.allowed_security_groups)} may access.")


def main():
    s = AuthorizationService(10, 20)
    user_group = s.get_current_user_group()
    s.validate_user()
    print(user_group)

    # Demonstrates negative side effects of mutation
    s.get_allowed_users()[0] = s.get_current_user_group()
    s.validate_user()


main()
