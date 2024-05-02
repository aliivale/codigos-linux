// valor para la comparacion 
// let usuario = "admin"; 
// let clabe= "admin"

// podria solo inicializarlas sin valor
// let usuario, clave;


let usuario = prompt("Ingrese su usuario");
let clave = prompt("Ingrese su clave");

if(usuario == "admin" && clave=="admin"){
    document.write("Ingreso exitoso!!");
}
else{
    alert("Usuario no encontrado");
}

