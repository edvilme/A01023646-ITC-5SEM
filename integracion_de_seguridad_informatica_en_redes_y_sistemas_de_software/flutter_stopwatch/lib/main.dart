import 'package:flutter/material.dart';
import 'package:flutter_stopwatch/stopwatch.dart';

void main() => runApp(StopwatchApp());

class StopwatchApp extends StatelessWidget{
	Widget build(BuildContext context){
		return MaterialApp(
			home: StopWatch()
		);
	}
}
