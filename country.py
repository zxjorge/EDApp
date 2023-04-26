import pycountry

print("{", end="")
for country in pycountry.countries:
    print("{" + f"\"{country.alpha_2.lower()}\", \"{country.name}\"" + "}", end=", ")

print("}")
