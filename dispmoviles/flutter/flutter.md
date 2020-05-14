Flutter
=====
Inspirado en java y javascript

## Notes 
* Siempre debe de tener la función main!

## Functions 
```dart
num getAnimals(String veterinaria){

}

getAnimals(veterinaria){ /*Tipo inferido. No se necesita especifar el tipo de variable*/
  return inventario[veterinaria];
}

num getAnimals(veterinaria) => inventario[veterinaria]
```

### Parameters 
```dart
num getAnimals([String veterinaria]){ /*Parámetro opcional*/
  return inventario[veterinaria];
}

num getAnimals({veterinaria = "Cats"}){ /*Parámetro default*/
  return inventario[veterinaria];
}
```

## Loops
### For

```dart
for(var animal in zoo){
  print("Este es un $animal"); /*imprimir variable*/
}

for(int bugs = 1; bugs <= 100; bugs++){
  print("Este es el bug #$bugs");
}

zoo.where((name) => name.contains('zebra')).forEach(print)
```

## Cascade
```dart
getAddress()
  ..setStreet("Elm", "13a")
  ..city = "Juan"
```

## Classes
```dart
class Address{
  String street;
  String city;
  String state;
  dynamic zip;

  Address(this.street, this.city, this.state, this.zip);

  Address.unknown() : this(null, null, null, null);

  getAddress(){
    return "La dirección ${this.street} es en la ciudad de ${this.city}, estado de ${this.state} con código postal ${this.zip}";
  }

}

void main() {
  var home = Address.unknown();
  home.street = "Calle Elm";
  home.city = "Querétaro";
  home.state = "Querétaro";
  home.zip = "76180";
  
  home
    ..street = "Elm Street"
    ..city = "Carthage"
    ..state = "Queretaro"
    ..zip = 6666;

  print(home.getAddress());
}
```
## Material
Widget collection to use material design guidelines

## Widgets
Base structure of Flutter.
