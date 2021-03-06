var net = require('net'); 
var HOST = '127.0.0.1';
var PORT = 18888;

var socket  = new net.Socket();
var msg = 'Hey! TCP server.';
socket.setNoDelay(true);
socket.connect(PORT, HOST, function() {
	console.log('client connected to : ' + HOST + ':' + PORT );
	//	socket.setTimeout( 1000 );
	socket.on('drain', function () {
		console.log('client occured drain >> write buffer is empty' );	
	})

	socket.on('data', function (data) {
		console.log('client received data >> ' + ' [' + data + ']' );	
	})

	socket.on('error', function (error) {
		console.error('client occured error >> ', error);
	});

	socket.on('timeout', function () {
		console.log('client occured timeout >> ' );	
	});

	socket.on('end', function () {
		console.log('client received end >> ');	
	});

	socket.on('close', function (error) {
		console.log('client closed >>' );	
		if (error) {
			console.log('The socket had a transmission error.');
		}		
	});



	var write_ok = socket.write(msg);
	console.log( 'client send data [%s] and end of write = %s', msg, write_ok );
	socket.end();

});
