import example

# p = example.Pet("Molly")
p = example.Pet('Polly', 'parrot')
print p

print p.name()

p.setName("Charly")

print p.name()

p.age = 2
print p.__dict__

### Derived Class
b = Dog('aaa')
example.dog_bark(b)
