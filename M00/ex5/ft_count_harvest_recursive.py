def ft_count_harvest_recursive():
    days = int(input("Days until harvest: "))
    day = 1

    def count_days(day, days):
        if day > days:
            return
        print("Day", day)
        count_days(day + 1, days)

    count_days(day, days)
    print("Harvest time!")
