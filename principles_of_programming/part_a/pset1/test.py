def dates_in_month(dates, month):
    if len(dates) == 0:
        return []
    elif dates[0][1] == month:
        ds = dates_in_month(dates[1:], month)
        ds.insert(0, dates[0])
        return ds
    else:
        return dates_in_month(dates[1:], month)

dates = [(2022, 9, 7), (1996, 5, 2), (2021, 4, 3), (1947, 5, 4), (1955, 4, 1), (1990, 1, 3), (2016, 4, 12)];
print(dates_in_month(dates, 4))