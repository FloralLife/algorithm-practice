function cmpStart(a, b) {
  if (a[0] === b[0]) return a[1] - b[1];
  return a[0] - b[0];
}

function cmpTime(a, b) {
  if (a[1] === b[1]) return a[0] - b[0];
  return a[1] - b[1];
}

function nextJobs(list, time) {
  const res = list.filter((elem) => elem[0] <= time);
  list.splice(0, res.length);
  return res;
}

function solution(jobs) {
  const list = jobs.sort(cmpStart);
  const n = jobs.length;
  const waiting = [list[0]];
  let time = waiting[0][0];
  let total = 0;
  list.splice(0, 1);
  while (waiting.length || list.length) {
    if (waiting.length) {
      waiting.sort(cmpTime);
      time += waiting[0][1];
      total += time - waiting[0][0];
      waiting.shift(0);
    } else time = list[0][0];
    const next = nextJobs(list, time);
    waiting.push(...next);
  }
  return Math.floor(total / n);
}
