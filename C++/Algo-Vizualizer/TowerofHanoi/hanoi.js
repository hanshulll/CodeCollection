const getId = id => document.getElementById(id);
const animateHanoiBtn = getId("animateHanoiBtn");
const answer = getId("answer");
const diskAmountInput = getId("diskAmountInput");
const pegsAmountInput = getId("pegsAmountInput");
const startingPegInput = getId("startingPegInput");
const endingPegInput = getId("endingPegInput");
const animationSpeed = getId("animationSpeed");
const fullAnimationCheckbox = getId("fullAnimationCheckbox");
const colorSelectorRed = getId("colorSelectorRed");
const colorSelectorGreen = getId("colorSelectorGreen");
const colorSelectorBlue = getId("colorSelectorBlue");
const redGradientCheckbox = getId("redGradientCheckbox");
const greenGradientCheckbox = getId("greenGradientCheckbox");
const blueGradientCheckbox = getId("blueGradientCheckbox");
const pauseCheckbox = getId("pauseCheckbox");
const nextStepBtn = getId("nextStepBtn");
const prevStepBtn = getId("prevStepBtn");

let canvas = document.getElementById("canvas");
let ctx = canvas.getContext("2d");

canvas.width = 1200;
canvas.height = 600;

class Hanoi {
  constructor() {
    this.init();
  }

  init() {
    this.movesArr = [];
  }

  move = (target, from, to) => {
    if (target < 1) return;
    let obj = {
      target,
      from,
      to
    };
    this.movesArr.push(obj);
  };

  ThreePegs = (number, start, middle, end) => {
    if (number < 1) return;
    this.ThreePegs(number - 1, start, end, middle);
    this.move(number, start, end);
    this.ThreePegs(number - 1, middle, start, end);
  };

  FourPegs = (num, start, mid1, mid2, end) => {
    if (num < 1) return;
    this.FourPegs(num - 2, start, mid1, end, mid2);
    this.move(num - 1, start, mid1);
    this.move(num, start, end);
    this.move(num - 1, mid1, end);
    this.FourPegs(num - 2, mid2, start, mid1, end);
  };

  FivePegs = (num, start, mid1, mid2, mid3, end) => {
    if (num < 1) return;
    this.FivePegs(num - 3, start, mid1, mid2, end, mid3);
    this.move(num - 2, start, mid2);
    this.move(num - 1, start, mid1);
    this.move(num, start, end);
    this.move(num - 1, mid1, end);
    this.move(num - 2, mid2, end);
    this.FivePegs(num - 3, mid3, start, mid1, mid2, end);
  };

  SixPegs = (num, start, mid1, mid2, mid3, mid4, end) => {
    if (num < 1) return;
    this.SixPegs(num - 4, start, mid1, mid2, mid3, end, mid4);
    this.move(num - 3, start, mid3);
    this.move(num - 2, start, mid2);
    this.move(num - 1, start, mid1);
    this.move(num, start, end);
    this.move(num - 1, mid1, end);
    this.move(num - 2, mid2, end);
    this.move(num - 3, mid3, end);
    this.SixPegs(num - 4, mid4, start, mid1, mid2, mid3, end);
  };

  SevenPegs = (num, start, mid1, mid2, mid3, mid4, mid5, end) => {
    if (num < 1) return;
    this.SevenPegs(num - 5, start, mid1, mid2, mid3, mid4, end, mid5);
    this.move(num - 4, start, mid4);
    this.move(num - 3, start, mid3);
    this.move(num - 2, start, mid2);
    this.move(num - 1, start, mid1);
    this.move(num, start, end);
    this.move(num - 1, mid1, end);
    this.move(num - 2, mid2, end);
    this.move(num - 3, mid3, end);
    this.move(num - 4, mid4, end);
    this.SevenPegs(num - 5, mid5, start, mid1, mid2, mid3, mid4, end);
  };

  EightPegs = (num, start, mid1, mid2, mid3, mid4, mid5, mid6, end) => {
    if (num < 1) return;
    this.EightPegs(num - 6, start, mid1, mid2, mid3, mid4, mid5, end, mid6);
    this.move(num - 5, start, mid5);
    this.move(num - 4, start, mid4);
    this.move(num - 3, start, mid3);
    this.move(num - 2, start, mid2);
    this.move(num - 1, start, mid1);
    this.move(num, start, end);
    this.move(num - 1, mid1, end);
    this.move(num - 2, mid2, end);
    this.move(num - 3, mid3, end);
    this.move(num - 4, mid4, end);
    this.move(num - 5, mid5, end);
    this.EightPegs(num - 6, mid6, start, mid1, mid2, mid3, mid4, mid5, end);
  };

  NinePegs = (num, start, mid1, mid2, mid3, mid4, mid5, mid6, mid7, end) => {
    if (num < 1) return;
    this.NinePegs(
      num - 7,
      start,
      mid1,
      mid2,
      mid3,
      mid4,
      mid5,
      mid6,
      end,
      mid7
    );
    this.move(num - 6, start, mid6);
    this.move(num - 5, start, mid5);
    this.move(num - 4, start, mid4);
    this.move(num - 3, start, mid3);
    this.move(num - 2, start, mid2);
    this.move(num - 1, start, mid1);
    this.move(num, start, end);
    this.move(num - 1, mid1, end);
    this.move(num - 2, mid2, end);
    this.move(num - 3, mid3, end);
    this.move(num - 4, mid4, end);
    this.move(num - 5, mid5, end);
    this.move(num - 6, mid6, end);
    this.NinePegs(
      num - 7,
      mid7,
      start,
      mid1,
      mid2,
      mid3,
      mid4,
      mid5,
      mid6,
      end
    );
  };

  TenPegs = (
    num,
    start,
    mid1,
    mid2,
    mid3,
    mid4,
    mid5,
    mid6,
    mid7,
    mid8,
    end
  ) => {
    if (num < 1) return;
    this.TenPegs(
      num - 8,
      start,
      mid1,
      mid2,
      mid3,
      mid4,
      mid5,
      mid6,
      mid7,
      end,
      mid8
    );
    this.move(num - 7, start, mid7);
    this.move(num - 6, start, mid6);
    this.move(num - 5, start, mid5);
    this.move(num - 4, start, mid4);
    this.move(num - 3, start, mid3);
    this.move(num - 2, start, mid2);
    this.move(num - 1, start, mid1);
    this.move(num, start, end);
    this.move(num - 1, mid1, end);
    this.move(num - 2, mid2, end);
    this.move(num - 3, mid3, end);
    this.move(num - 4, mid4, end);
    this.move(num - 5, mid5, end);
    this.move(num - 6, mid6, end);
    this.move(num - 7, mid7, end);
    this.TenPegs(
      num - 8,
      mid8,
      start,
      mid1,
      mid2,
      mid3,
      mid4,
      mid5,
      mid6,
      mid7,
      end
    );
  };
}

class HanoiVisualization {
  constructor() {
    this.init();
  }

  init = () => {
    this.animationQueue = [];

    this.queuedSteps = [];
    this.prevSteps = [];

    this.animating = null;
    this.setAnimating(false);
    this.pegsArr = [];
    this.setPegsAndDisksArr();

    this.moveDesc = "";
    this.curMove = 0;
    this.totalMoves = 0;

    this.getHanoiSolution();
  };

  setAnimating = bool => {
    this.animating = bool;
    animateHanoiBtn.disabled = bool;
  };

  setTotalMoves = val => (this.totalMoves = val);

  getPegsIds = () => {
    let pegsIds = [];

    for (let i = 0; i < this.pegsArr.length; i++) {
      if (i === options.startingPeg || i === options.endingPeg) continue;
      pegsIds.push(this.pegsArr[i].id);
    }

    pegsIds.unshift(options.startingPeg);
    pegsIds.push(options.endingPeg);

    return pegsIds;
  };

  getHanoiSolution = () => {
    let diskAmount = options.diskAmount;
    let pegs = this.getPegsIds();

    switch (options.pegsAmount) {
      case 3:
        hanoi.ThreePegs(diskAmount, ...pegs);
        break;
      case 4:
        hanoi.FourPegs(diskAmount, ...pegs);
        break;
      case 5:
        hanoi.FivePegs(diskAmount, ...pegs);
        break;
      case 6:
        hanoi.SixPegs(diskAmount, ...pegs);
        break;
      case 7:
        hanoi.SevenPegs(diskAmount, ...pegs);
        break;
      case 8:
        hanoi.EightPegs(diskAmount, ...pegs);
        break;
      case 9:
        hanoi.NinePegs(diskAmount, ...pegs);
        break;
      case 10:
        hanoi.TenPegs(diskAmount, ...pegs);
        break;
      default:
        alert("Error determining number of pegs");
    }

    this.displayMovesInHtml(hanoi.movesArr);

    this.fillQueue(hanoi.movesArr);

    this.setTotalMoves(this.queuedSteps[0].totalMoves);

    hanoi.init();
  };

  startAnimating = () => this.setAnimating(true);

  displayMovesInHtml = movesArr => {
    answer.innerHTML = "";
    movesArr.forEach((move, idx) => {
      let moveNumber = idx + 1;
      let moveDiv = document.createElement("div");
      moveDiv.innerHTML = `${moveNumber}) Move disk ${
        move.target
      } from ${options.getPegChar(move.from)} to ${options.getPegChar(
        move.to
      )}`;
      answer.appendChild(moveDiv);
    });
  };

  drawPegs = pegsPos => {
    ctx.lineWidth = 10;
    for (let i = 0; i < pegsPos.length; i++) {
      ctx.beginPath();
      ctx.moveTo(pegsPos[i].x1, pegsPos[i].y1);
      ctx.lineTo(pegsPos[i].x2, pegsPos[i].y2);
      ctx.stroke();

      ctx.font = `20px Arial`;
      ctx.fillStyle = "black";
      let text = options.getPegChar(pegsPos[i].id);
      ctx.fillText(text, pegsPos[i].x2, pegsPos[i].y2 - 5);
    }
  };

  getDiskColor = i => {
    let n = options.diskAmount;
    let red = options.redGradient
      ? this.calculateDiskColor(options.redVal, n, i)
      : options.redVal;
    let green = options.greenGradient
      ? this.calculateDiskColor(options.greenVal, n, i)
      : options.greenVal;
    let blue = options.blueGradient
      ? this.calculateDiskColor(options.blueVal, n, i)
      : options.blueVal;
    return `rgb(${red}, ${green}, ${blue})`;
  };

  calculateDiskColor(val, n, i) {
    return val - (val / n) * (i - 1);
  }

  drawDisk = (target, x, y, width, height) => {
    ctx.lineWidth = 1;
    ctx.fillStyle = this.getDiskColor(target);

    ctx.beginPath();
    ctx.rect(x, y, width, height);
    ctx.fill();
    ctx.stroke();

    ctx.font = `${height}px Arial`;
    ctx.textAlign = "center";
    ctx.fillStyle = "white";
    ctx.fillText(target, x + width / 2, y + height * 0.875);
  };

  initPegs = () => {
    let pegsArr = [];
    let pegsAmount = options.pegsAmount;

    let pegSpacing = canvas.width / (pegsAmount + 1);
    let lastPegPos = pegSpacing * (pegsAmount - 1);
    let margin = (canvas.width - lastPegPos) / 2;

    for (let i = 0; i < pegsAmount; i++) {
      let x = pegSpacing * i;
      let pos = {
        id: i,
        x1: margin + x,
        y1: canvas.height,
        x2: margin + x,
        y2: canvas.height * 0.3,
        disks: []
      };

      pegsArr.push(pos);
    }

    return pegsArr;
  };

  initDisks = pegsArr => {
    let diskAmount = options.diskAmount;

    let height = 40;
    let floor = pegsArr[options.startingPeg].y1 - height;

    let pegSpacing = canvas.width / (pegsArr.length + 1);
    let biggestDisk = pegSpacing / 1.5;
    let smallestDisk = 10;

    let diskSizeRange = biggestDisk - smallestDisk;
    let averageSizeChange = diskSizeRange / diskAmount;

    for (let i = diskAmount; i > 0; i--) {
      let width = smallestDisk + averageSizeChange * (i + 1);

      let x = pegsArr[options.startingPeg].x1 - width / 2;
      let y = floor - height * pegsArr[options.startingPeg].disks.length;

      let diskObj = {
        id: i,
        x,
        y,
        width,
        height,
        draw: true
      };

      pegsArr[options.startingPeg].disks.push(diskObj);
    }
  };

  drawAllDisks = pegsArr => {
    for (let i = 0; i < pegsArr.length; i++) {
      for (let j = 0; j < pegsArr[i].disks.length; j++) {
        let disk = pegsArr[i].disks[j];
        if (disk.draw) {
          this.drawDisk(disk.id, disk.x, disk.y, disk.width, disk.height);
        }
      }
    }
  };

  setPegsAndDisksArr = () => {
    this.pegsArr = this.initPegs();
    this.initDisks(this.pegsArr);
  };

  drawMoveDesc = (str, size = 30) => {
    ctx.font = `${size}px Arial`;
    ctx.textAlign = "center";
    ctx.fillStyle = "#46A049";
    ctx.fillText(str, canvas.width / 2, 10 + size);
  };

  drawMoveCounter(cur, total, size = 20) {
    ctx.font = `${size}px Arial`;
    ctx.textAlign = "center";
    ctx.fillStyle = "#46A049";
    ctx.fillText(`${cur} / ${total}`, canvas.width / 2, 45 + size);
  }

  fillQueue = movesArr => {
    for (let i = 0; i < movesArr.length; i++) {
      let target = movesArr[i].target;
      let from = movesArr[i].from;
      let to = movesArr[i].to;

      this.queuedSteps.push({
        oldPeg: this.pegsArr[from],
        newPeg: this.pegsArr[to],
        moveDesc: `Move disk ${target} from ${options.getPegChar(
          from
        )} to ${options.getPegChar(to)}`,
        curMove: i + 1,
        totalMoves: movesArr.length
      });
    }
  };

  moveDisk = (disk, endPeg) => {
    endPeg.disks.push(disk);

    disk.x = endPeg.x1 - disk.width / 2;
    disk.y = endPeg.y1 - disk.height * endPeg.disks.length;
  };

  hideDisk = disk => {
    disk.draw = false;
  };

  showDisk = disk => {
    disk.draw = true;
  };

  fillAnimationQueue = (disk, endPeg) => {
    this.hideDisk(disk);

    let diskCopy = Object.assign({}, disk);

    let y_Lift = endPeg.y2 - disk.height - 30;
    let x_Final = endPeg.x1 - disk.width / 2;
    let y_Final = endPeg.y1 - disk.height * (endPeg.disks.length + 1);

    const getAnimDirection = (cur, end) => (cur - end < 0 ? "+" : "-");

    const getTotalDistance = (cur, end) =>
      cur - end < 0 ? end - cur : cur - end;

    const createAnimSegment = (startPos, endPos, axis) => {
      return {
        diskCopy,
        endPos,
        axis,
        animDirection: getAnimDirection(startPos, endPos),
        totalDistance: getTotalDistance(startPos, endPos)
      };
    };

    this.animationQueue.push([
      disk,
      [
        createAnimSegment(disk.y, y_Lift, "y"),
        createAnimSegment(disk.x, x_Final, "x"),
        createAnimSegment(y_Lift, y_Final, "y")
      ]
    ]);
  };

  getNewAnimDiskPos = (curPos, endPos, velocity) => {
    if (
      (curPos < endPos && velocity < 0) ||
      (curPos > endPos && velocity > 0)
    ) {
      return null;
    } else {
      return curPos + velocity;
    }
  };

  endTargetDiskAnimation = disk => {
    this.showDisk(disk);
    this.animationQueue.shift();
  };

  executeAnimationQueue = (deltaTime, animSpeed) => {
    let diskOrig = this.animationQueue[0][0];
    let currentAnimationArr = this.animationQueue[0][1];

    if (!currentAnimationArr.length) {
      return this.endTargetDiskAnimation(diskOrig);
    }

    let curSegment = currentAnimationArr[0];
    let diskCopy = curSegment.diskCopy;
    let endPos = curSegment.endPos;
    let axis = curSegment.axis;
    let animDirection = curSegment.animDirection;
    let totalDistance = curSegment.totalDistance;

    let time = animSpeed / 4;
    let speed = (totalDistance / time) * deltaTime;
    let velocity = +(animDirection + speed);

    if (totalDistance === 0) {
      currentAnimationArr.shift();
    }

    let pos = this.getNewAnimDiskPos(diskCopy[axis], endPos, velocity);
    if (pos === null) {
      diskCopy[axis] = endPos;
      currentAnimationArr.shift();
    } else {
      diskCopy[axis] = pos;
    }

    this.drawDisk(
      diskCopy.id,
      diskCopy.x,
      diskCopy.y,
      diskCopy.width,
      diskCopy.height
    );
  };

  executeQueuedStep = () => {
    if (this.queuedSteps.length > 0) {
      let moveData = this.queuedSteps.shift();

      let disk = moveData.oldPeg.disks.pop();

      if (options.playFullAnim) {
        this.fillAnimationQueue(disk, moveData.newPeg);
      }

      this.moveDisk(disk, moveData.newPeg);
      this.moveDesc = moveData.moveDesc;
      this.curMove = moveData.curMove;

      this.prevSteps.push(moveData);
    } else {
      this.setAnimating(false);
    }
  };

  getPrevStep = () => {
    if (this.prevSteps.length > 0) {
      if (!this.animating) this.setAnimating(true);

      let moveData = this.prevSteps.pop();

      let disk = moveData.newPeg.disks.pop();

      this.moveDisk(disk, moveData.oldPeg);
      this.moveDesc = moveData.moveDesc;
      this.curMove = moveData.curMove;

      this.queuedSteps.unshift(moveData);
    }
  };

  animateSolution = (deltaTime, animSpeed) => {
    timeout += deltaTime;

    if (timeout > animSpeed) {
      hanoiVis.executeQueuedStep();
      timeout = 0;
    }
  };

  draw = (deltaTime, animSpeed) => {
    this.drawPegs(this.pegsArr);

    if (this.animating && !options.paused) {
      this.animateSolution(deltaTime, animSpeed);
    }

    if (!!this.animationQueue.length) {
      this.executeAnimationQueue(deltaTime, animSpeed);
    }

    this.drawMoveDesc(this.moveDesc);
    this.drawMoveCounter(this.curMove, this.totalMoves);

    this.drawAllDisks(this.pegsArr);
  };
}

class Options {
  constructor() {
    this.initVariables();
    this.initEventListeners();
  }

  initVariables = () => {
    this.diskAmount = +diskAmountInput.value;
    this.pegsAmount = +pegsAmountInput.value;

    this.populateTargetPegsInputs();
    this.startingPeg = +startingPegInput.value;
    this.endingPeg = +endingPegInput.value;

    this.animSpeed = +animationSpeed.value;
    this.playFullAnim = fullAnimationCheckbox.checked;
    this.paused = false;

    this.redVal = +colorSelectorRed.value;
    this.greenVal = +colorSelectorGreen.value;
    this.blueVal = +colorSelectorBlue.value;
    this.redGradient = +redGradientCheckbox.checked;
    this.greenGradient = +greenGradientCheckbox.checked;
    this.blueGradient = +blueGradientCheckbox.checked;
  };

  initEventListeners = () => {
    //#region - Disk and peg options listeners
    diskAmountInput.oninput = e => {
      let num = this.clampNumber(e.target);
      this.diskAmount = diskAmountInput.value = num;
      hanoiVis.init();
    };

    pegsAmountInput.onchange = e => {
      let num = this.clampNumber(e.target);
      this.pegsAmount = pegsAmountInput.value = num;
      this.populateTargetPegsInputs();
      this.startingPeg = +startingPegInput.value;
      this.endingPeg = +endingPegInput.value;
      hanoiVis.init();
    };

    startingPegInput.onchange = e => {
      this.startingPeg = +e.target.value;
      this.populateTargetPegsInputs(this.startingPeg, this.endingPeg);
      hanoiVis.init();
    };

    endingPegInput.onchange = e => {
      this.endingPeg = +e.target.value;
      this.populateTargetPegsInputs(this.startingPeg, this.endingPeg);
      hanoiVis.init();
    };
    //#endregion - Disk and peg options listeners

    //#region - Animation options listeners
    fullAnimationCheckbox.onchange = () => {
      this.playFullAnim = fullAnimationCheckbox.checked;

      fullAnimationCheckbox.checked
        ? (animationSpeed.min = 500)
        : (animationSpeed.min = 1);

      this.setAnimSpeed(animationSpeed);
    };

    animateHanoiBtn.onclick = () => {
      hanoiVis.init();
      hanoiVis.startAnimating();
      pauseCheckbox.disabled = false;
    };

    animationSpeed.onchange = e => this.setAnimSpeed(e.target);
    //#endregion - Animation options listeners

    //#region - Pause and step options listeners
    pauseCheckbox.onchange = () => {
      let bool = pauseCheckbox.checked;
      this.paused = bool;
      nextStepBtn.disabled = !bool;
      prevStepBtn.disabled = !bool;
      fullAnimationCheckbox.disabled = bool;
      fullAnimationCheckbox.checked = !bool;
      fullAnimationCheckbox.onchange();
    };

    nextStepBtn.onclick = () => hanoiVis.executeQueuedStep();
    prevStepBtn.onclick = () => hanoiVis.getPrevStep();
    //#endregion - Pause and step options listeners

    //#region - Color options listeners
    colorSelectorRed.oninput = e =>
      (this.redVal = colorSelectorRed.value = this.clampNumber(e.target));
    colorSelectorGreen.oninput = e =>
      (this.greenVal = colorSelectorGreen.value = this.clampNumber(e.target));
    colorSelectorBlue.oninput = e =>
      (this.blueVal = colorSelectorBlue.value = this.clampNumber(e.target));

    redGradientCheckbox.onchange = e => (this.redGradient = e.target.checked);
    greenGradientCheckbox.onchange = e =>
      (this.greenGradient = e.target.checked);
    blueGradientCheckbox.onchange = e => (this.blueGradient = e.target.checked);
    //#endregion - Color options listeners
  };

  populateTargetPegsInputs = (start = 0, end = this.pegsAmount - 1) => {
    startingPegInput.innerHTML = "";
    endingPegInput.innerHTML = "";

    for (let i = 0; i < this.pegsAmount; i++) {
      let opt = document.createElement("option");
      opt.text = this.getPegChar(i);
      opt.value = i;

      if (i === start) opt.selected = true;
      if (i === end) opt.disabled = true;

      startingPegInput.add(opt, null);
    }

    for (let i = 0; i < this.pegsAmount; i++) {
      let opt = document.createElement("option");
      opt.text = this.getPegChar(i);
      opt.value = i;

      if (i === start) opt.disabled = true;
      if (i === end) opt.selected = true;

      endingPegInput.add(opt, null);
    }
  };

  getPegChar = n => String.fromCharCode(65 + n);

  setAnimSpeed = target => {
    let ms = this.clampNumber(target);
    this.animSpeed = animationSpeed.value = ms;
  };

  clampNumber = target => {
    let val = +target.value;
    let min = +target.min;
    let max = +target.max;
    if (val < min) return min;
    if (val > max) return max;
    return val;
  };
}

const options = new Options();
const hanoi = new Hanoi();
const hanoiVis = new HanoiVisualization();

let lastTime = 0,
  timeout = 0,
  deltaTime;

function step(timestamp) {
  deltaTime = timestamp - lastTime;
  lastTime = timestamp;

  ctx.clearRect(0, 0, canvas.width, canvas.height);

  hanoiVis.draw(deltaTime, options.animSpeed);

  window.requestAnimationFrame(step);
}

window.requestAnimationFrame(step);
