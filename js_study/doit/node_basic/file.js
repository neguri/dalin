// file read
var fs = require('fs');
// ���� ���
var data = fs.readFileSync('./package.json','utf-8');

console.log(data);
// �ٹٲ��� �ȸ���
console.dir(data);

// �񵿱� ���
fs.readFile('./package.json','utf-8',function(err,data) {
	console.log(data);
  }
);


// file write

var wf = require('fs');
fs.writeFile('./output.txt','hello',function(err) {
	if(err) {
		console.log('write error');

	}else{
		console.log('write success');
	}
});

