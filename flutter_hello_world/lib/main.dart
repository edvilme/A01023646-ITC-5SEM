import 'package:flutter/material.dart';
import 'dart:math';

// Como en C, C++, Java, etc., el main es la primera función que se llama, y puede recibir argumentos desde la terminal
void main(List<String> args) {
	// El método runApp recibe un widget para ejecutar la aplicación
	runApp(MyAppContainer());
}

// Se necesita un contenedor que regrese una MaterialApp
class MyAppContainer extends StatelessWidget {
	Widget build(BuildContext context){
		return MaterialApp(
			title: 'Generador de nombres aleatorio',
			home: HomePage()
		);
	}
}

// Un stateful widget se actualiza cada que cambie un estado
class HomePage extends StatefulWidget {
	HomePage({Key? key}) : super(key: key);
	HomePageState createState() => HomePageState();
}

// Acá se define el estado que irá cambiando
class HomePageState extends State<HomePage>{
	// Crea un color random
	Color createRandomColor(){
		Random rmd = new Random();
		return Color.fromRGBO(rmd.nextInt(255), rmd.nextInt(255), rmd.nextInt(255), 1);
	}
	String colorToHex(Color c){
		String r = c.red.toRadixString(16).padLeft(2, '0').toUpperCase();
		String g = c.green.toRadixString(16).padLeft(2, '0').toUpperCase();
		String b = c.blue.toRadixString(16).padLeft(2, '0').toUpperCase();
		return "#"+r+g+b;
	}
	// Para poder hacer scroll
	ScrollController _scrollController = new ScrollController();
	void _scrollToTop(){
		_scrollController.jumpTo(0);
	}
	// Layout de app
	Widget build(BuildContext context){
		return Scaffold(
			appBar: AppBar(title: Text("Random color generator")),
			body: ListView.builder(itemBuilder: (context, index) {
				Color c = createRandomColor();
				return Container(
					padding: const EdgeInsets.symmetric(vertical: 16, horizontal: 8),
					decoration: BoxDecoration(
						color: c
					),
					child: Text(
						// "("+index.toString()+") "+c.toString(), 
						'(${index.toString()}) ${colorToHex(c)}',
						style: TextStyle(
							color: c.computeLuminance() > 0.5 ? Colors.black : Colors.white
						),
					),
				);
			}, controller: _scrollController),
			floatingActionButton: FloatingActionButton(
				onPressed: _scrollToTop,
				tooltip: 'Increment',
				child: Icon(Icons.arrow_upward),
			),
		);
	}
}
