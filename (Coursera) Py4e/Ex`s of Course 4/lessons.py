# 14.3 - Object Life Cycle
class PartyAnimal:           # This is the template for making PartyAnimal objects
    x = 0 # instance 'x'     # Each PartyAnimal object has a bit of data
    name = None # instance 'name'
    def __init__(self, nam): # Constructor. 'self' is an alias for 'an'
        self.name = nam      # Whole idea of the constructor is just to grab 'name' (or another) parameter
        print(self.name, 'constructed')

    def party(self):         # Each PartyAnimal object has a bit of code (method 'party')
        self.x += 1
        print(self.name, 'party count',self.x)

    def __del__(self):       # Destructor
        print(self.name, 'destructed', self.x)

an = PartyAnimal('Jim') # Construct PartyAnimal object and store in a variable ( same as "an = list()" )
an.party() #              == PartyAnimal.party(an)    Run party() code within it
PartyAnimal.party(an) #   == an.party()               Run party() code within it
an = 42 # Jim destructed 2
print('an contains',an) # an contains 42

# 14.4 - Object Inheritance
# from party import PartyAnimal
class FootballFan(PartyAnimal): # FootballFan (child) is a class which extends PartyAnimal (parent)
    points = 0 # instance 'points'
    def touchdown(self): # method 'touchdown'
        self.points = self.points + 7
        self.party()
        print(self.name,"points",self.points) # Extension

s = PartyAnimal("Sally")
s.party()
j = FootballFan("Max")
j.party()
j.touchdown()
print(dir(j)) # It has all the capabilities of PartyAnimal and more
