function matchNumber(n, number) {
  return n === number;
}

function solution(N, number) {
  const expressedNumbers = Array.from(Array(8), () => []);
  for (const [idx, e] of expressedNumbers.entries()) {
    let n = "";
    for (let i = 0; i <= idx; i++) {
      n += N;
    }
    n = parseInt(n);
    if (matchNumber(n, number)) return idx + 1;
    e.push(n);
  }

  for (let i = 0; i < 8; i++) {
    for (let j = 0; j < i; j++) {
      for (const n1 of expressedNumbers[j]) {
        for (const n2 of expressedNumbers[i - j - 1]) {
          let result = n1 + n2;
          if (matchNumber(result, number)) return i + 1;
          expressedNumbers[i].push(result);
          result = n1 - n2;
          if (matchNumber(result, number)) return i + 1;
          expressedNumbers[i].push(result);
          result = n1 * n2;
          if (matchNumber(result, number)) return i + 1;
          expressedNumbers[i].push(result);
          if (n2 !== 0) {
            result = Math.floor(n1 / n2);
            if (matchNumber(result, number)) return i + 1;
            expressedNumbers[i].push(result);
          }
        }
      }
    }
  }
  return -1;
}
