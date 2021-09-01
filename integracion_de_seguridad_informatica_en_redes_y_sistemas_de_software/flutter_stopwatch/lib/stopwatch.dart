import 'dart:async';
import 'package:flutter/material.dart';

class StopWatch extends StatefulWidget{
	State createState() => StopWatchState();
}

class StopWatchState extends State<StopWatch>{
	late int milliseconds;
	late Timer timer;
	late bool isTicking;

	final laps = <int>[];
	final lapListScrollController = ScrollController();
	final double lapListItemHeight = 60;

	@override
	void initState(){
		super.initState();
		milliseconds = 0;
		timer = Timer.periodic(Duration(milliseconds: 1), _onTick);
		isTicking = true;
	}

	void _onTick(Timer time){
		setState(() => ++milliseconds);
	}

	@override
	void dispose(){
		timer.cancel();
		super.dispose();
	}

	void _startTimer(){
		timer = Timer.periodic(Duration(seconds: 1), _onTick);
		laps.clear();
		setState((){
			isTicking = true;
			milliseconds = 0;
		});
	}

	void _endTimer(){
		timer.cancel();
		setState(() => isTicking = false);
	}

	void _addLap(){
		setState(() {
			laps.add(milliseconds);
			milliseconds = 0;
		});
		lapListScrollController.animateTo(lapListItemHeight*laps.length, curve: Curves.easeIn, duration: Duration(milliseconds: 500));
	}

	Widget _buildCounter(BuildContext context){
		return Container(
			child: Column(
				mainAxisAlignment: MainAxisAlignment.center,
				children: [
					Center(
						child: Text(
							'Lap ${laps.length + 1}',
							style: Theme.of(context)
								.textTheme 
								.subtitle1!
								.copyWith(color: Colors.white)
						)
					),
					Center(
						child: Text(
							'${milliseconds/1000} second${milliseconds/1000 == 1 ? '' : 's'}',
							style: Theme.of(context)
								.textTheme
								.headline2!
								.copyWith(color: Colors.white)
						)
					)
				],
			)
		);
	}

	Widget _buildControls(BuildContext context){
		return Container(
			padding: const EdgeInsets.symmetric(vertical: 8),
			child: Row(
				mainAxisAlignment: MainAxisAlignment.center,
				children: [
					ElevatedButton(
						onPressed: _startTimer,
						style: ButtonStyle(
							backgroundColor: MaterialStateProperty.all(Colors.green), 
							foregroundColor: MaterialStateProperty.all(Colors.white)
						),
						child: Text('Start'),
					), 
					SizedBox(width: 20),
					ElevatedButton(
						onPressed: _addLap,
						style: ButtonStyle(
							backgroundColor: MaterialStateProperty.all(Colors.yellow),
							foregroundColor: MaterialStateProperty.all(Colors.black)
						), 
						child: Text('Lap')
					),
					SizedBox(width: 20),
					ElevatedButton(
						onPressed: _endTimer,
						style: ButtonStyle(
							backgroundColor: MaterialStateProperty.all(Colors.red), 
							foregroundColor: MaterialStateProperty.all(Colors.white)
						),
						child: Text('Stop'),
					)
				],
			),
		);
	}

	Widget _buildLapList(){
		return ListView.builder(
			controller: lapListScrollController,
			itemCount: laps.length,
			itemExtent: lapListItemHeight,
			itemBuilder: (context, index) {
				int lapDuration = laps[index];
				return ListTile(
					title: Text('Lap ${index+1}'),
					trailing: Text('${lapDuration/1000} second${lapDuration/1000 == 1 ? '' : 's'}'),
				);
			},
		);
		/* return ListView(
			physics: BouncingScrollPhysics(),
			children: laps.asMap().entries.map((entry){
				int lapIndex = entry.key;
				int lapDuration = entry.value;
				return ListTile(
					title: Text('${lapDuration/1000} second${lapDuration/1000 == 1 ? '' : 's'}'),
					subtitle: Text('Lap $lapIndex')
				);
			}).toList(),
		); */
	}

	Widget build(BuildContext context){
		return Scaffold(
			appBar: AppBar( 
				title: Text('Stopwatch'),
			),
			body: Column(
				// mainAxisAlignment: MainAxisAlignment.center,
				children: [
					Container(
						padding: const EdgeInsets.symmetric(vertical: 16),
						color: Theme.of(context).primaryColor,
						child: Column(
							children: [
								_buildCounter(context),
								_buildControls(context)
							]
						)
					),
					Expanded(child: _buildLapList())
				],
			)
		);
	}
}