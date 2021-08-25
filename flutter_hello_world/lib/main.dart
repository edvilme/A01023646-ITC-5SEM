import 'dart:html';

import 'package:flutter/material.dart';
import 'dart:math';

import 'package:flutter/services.dart';

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


// Acá se define el estado que irá cambiando
class HomePageState extends State<HomePage>{

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
				Color color = createRandomColor();
				Color textColor = color.computeLuminance() > 0.5 ? Colors.black : Colors.white;
				String hexColor = colorToHex(color);
				return Container(
					decoration: BoxDecoration(
						color: color
					),
					child: ListTile(
						title: Text(hexColor,
							style: TextStyle(color: textColor),
						),
						subtitle: Text(index.toString(),
							style: TextStyle(color: textColor),
						),
						trailing: Icon(
							Icons.chevron_right,
							color: textColor,
						),
						onTap: (){
							showModalBottomSheet<void>(context: context, builder: (BuildContext context) {
								// return Text("Hi");
								return Container(
									decoration: BoxDecoration(
										color: color
									),
									padding: const EdgeInsets.all(16),
									child: Column(children: [
										Text(hexColor, 
											style: TextStyle(
												fontSize: 24,
												color: textColor
											),
										),
										Text("Lorem ipsum dolor sit amet. Disfruté mucho hacer esta app en Flutter",
											style: TextStyle(
												color: textColor
											),
										),
										ElevatedButton(
											child: Text('Copy'),
											onPressed: (){
												Clipboard.setData(ClipboardData(text: hexColor));
											},
										)
									])
								);
							});
						}
					),
				);
			}, controller: _scrollController),
			floatingActionButton: FloatingActionButton(
				onPressed: _scrollToTop,
				tooltip: 'Go to top',
				child: Icon(Icons.arrow_upward),
			),
		);
	}
}

