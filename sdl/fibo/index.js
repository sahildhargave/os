function generateFibonacci(){
	const inputElement = document.getElementById('fibo-input');
	const outputElement = document.getElementById('fibo-output');
   
	// clear previos result;
	outputElement.innerHTML = '';

	const n = parseInt(inputElement.value);
	if (isNaN(n) || n< 1){
		outputElement.textContent = 'Please enter a valid positive number.';
		return;
	}
     
	let fibseries = [];
	let a=0,b=1;
	for(let i=0;i<n;i++){
	fibseries.push(a);
	let next= a+b;
    a=b;
	b=next;
	}


	// displaying the fibonacci series
const fibonacciHtml = fibseries.map(num => `<span>${num}</span>`).join(',');
outputElement.innerHTML = `<p>Fibonacci Series (${n} numbers):</p><p>${fibonacciHtml}</p>`;
}

