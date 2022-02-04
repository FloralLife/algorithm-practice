function matchNumber(n, number){
	return n === number;
}

function solution(N, number) {
	const expressedNumbers = Array.from(Array(8), () => []);
	for(const (e, idx) of expressedNumbers) {
			let n = '';
			for(let i = 0; i <= idx; i++){
					n += N;
			}
			n = parseInt(n);
			if (matchNumber(n, number)) return idx + 1;
			e.push(n);
	}

	for (let i = 0; i < 8; i++){
			for(let j = 0; j < i; j++){

			}
	}
}
