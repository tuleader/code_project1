date = input()
date_components = date.split("-")
year_arr=[str(i).zfill(4) for i in range(1,10000)]
month_arr=[str(i).zfill(2) for i in range(1,13)]
day_arr = [str(i).zfill(2) for i in range(1, 32)]
# Kiểm tra xem có đủ 3 thành phần trong danh sách không
if len(date_components) != 3:
    print("INCORRECT")
else:
    year, month, day = date_components
    if year in year_arr and month in month_arr and day in day_arr:
        year = int(year)
        month = int(month)
        day=int(day)
        print(f'{year} {month} {day}')
    else:
        print('INCORRECT')
