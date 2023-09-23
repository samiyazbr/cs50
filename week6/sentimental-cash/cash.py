from cs50 import get_float


def get_cents():
    while True:
        try:
            cents = get_float("Cents Owed: ")
            if cents >= 0:
                return cents
            else:
                print("Amount owed must be non-negative.")
        except ValueError:
            print("Invalid input. Please enter a valid number.")


def calculate_coins(cents, coin_value):
    count = 0
    while cents >= coin_value:
        cents -= coin_value
        count += 1
    return count


def main():
    # Ask how many cents the customer is owed
    cents = get_cents()

    # Convert cents to the total number of cents (as an integer)
    total_cents = int(cents * 100)

    # Define coin values
    quarter_value = 25
    dime_value = 10
    nickel_value = 5
    penny_value = 1

    # Calculate the number of each type of coin to give the customer
    quarters = calculate_coins(total_cents, quarter_value)
    total_cents -= quarters * quarter_value

    dimes = calculate_coins(total_cents, dime_value)
    total_cents -= dimes * dime_value

    nickels = calculate_coins(total_cents, nickel_value)
    total_cents -= nickels * nickel_value

    pennies = calculate_coins(total_cents, penny_value)

    # Sum coins
    coins = quarters + dimes + nickels + pennies

    # Print total number of coins to give the customer
    print(coins)


main()
