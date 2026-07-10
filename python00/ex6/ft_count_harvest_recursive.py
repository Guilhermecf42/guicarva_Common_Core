def ft_count_harvest_recursive(day = 1, total = 0):
	if (total <= 0):
		total = int(input("Days until harvest: "))
	if (day <= total):
		print(f"Day {day}")
		ft_count_harvest_recursive(day + 1, total)
	else:
		print("Harvest time!")
