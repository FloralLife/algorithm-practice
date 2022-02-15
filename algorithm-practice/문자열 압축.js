function solution(s) {
	const answer = [];
	for(let n = 1; n <= Math.floor(s.length / 2); n++){
			answer.push('');
			let cnt = 0;
			let str = '';
			for(let i = 0; i < s.length; i += n){
					const newstr = s.slice(i, i + n);
					if (str === newstr) cnt++;
					else {
							if (cnt <= 1) answer[n - 1] += str;
							else if (cnt > 1) answer[n - 1] += `${cnt}${str}`;
							str = newstr;
							cnt = 1;
					}
					if (i + n >= s.length) {
							if (cnt <= 1) answer[n - 1] += str;
							else if (cnt > 1) answer[n - 1] += `${cnt}${str}`;
					}
			}
	}

	return answer.reduce((min, str) => min < str.length ? min : str.length, s.length);


}
