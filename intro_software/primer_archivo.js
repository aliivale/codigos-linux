// Tiene tipado
//     implicito --> sabe de que tipo es nuestra variable
//     debil --> deja hacer operaciones no APTAS. ej: entero + string
//     dinamico

// declaramos variables . Se usa mas el declaramiento con Kamel Case
let numero=7;
// otra forma de declarar VARIABLE CONSTANTE
const variable_constante=3;
//para VARIABLES GLOBALES
var n="Alisson";
// devuelve el tipo de dato
typeof numero;

//imprimimos 
console.log("HOLA MUNDO!");

// compara el valor y el tipo ===


//CONDICIONALES
if( 2 < 4){
    console.log("2 es menor que 4");
}
else if(4 > 1 ){
    console.log("4 es mayor a 1");
}
else{
    console.log("Eso es mentira");
}

//BUCLE FOR
for (let j = 10; j >0;j--){
    console.log(j);
}


//FUNCIONES parecido a C
function saludar_persona(nombre){
    console.log("Hola " + nombre);
}

//llamamos a la funcion
saludar_persona("ali");
