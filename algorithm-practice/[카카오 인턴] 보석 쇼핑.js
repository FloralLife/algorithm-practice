const MIN = 10000000;

function allInclude(gem) {
	for (let i in gem)
		if (gem[i] === 0) return false;
	return true;
}

function solution(gems) {
	var answer = [];
	let minlen = MIN;
	let gem = {};
	let start;
	for (let g = 0; g < gems.length; g++) {
		if (!gem.hasOwnProperty(gems[g])) {
			gem[gems[g]] = 0;
			start = g;
		}
	}
	let l = 0;
	for (let g = 0; g < gems.length; g++) {
		gem[gems[g]]++;
		if (g < start) continue;
		while (1) {
			let ml = g - l;
			if (minlen > ml) {
				minlen = ml;
				answer = [l + 1, g + 1];
			}
			gem[gems[l]]--;
			if (gem[gems[l]] === 0) {
				g++;
				while (gems[l] != gems[g]) {
					gem[gems[g++]]++;
					if (g >= gems.length) return answer;
				}
				l++;
				g--;
				break;
			}
			l++;
		}

	}
	return answer;
}
