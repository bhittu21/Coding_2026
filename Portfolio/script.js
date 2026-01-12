import * as THREE from 'three';
import { OrbitControls } from 'three/addons/controls/OrbitControls.js';

// --- DATA CONFIGURATION ---
const ventures = ["Tresifylab", "Aolo Software"];
const skills = [
    "AI", "C++", "Python", "C", "HTML", "CSS", 
    "WordPress", "Elementor", "Figma", "AI Agents", 
    "React", "Microsoft Tools"
];

// --- SCENE SETUP ---
const scene = new THREE.Scene();
scene.fog = new THREE.FogExp2(0x050505, 0.02);

const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
camera.position.set(0, 5, 15);

const renderer = new THREE.WebGLRenderer({ antialias: true, alpha: true });
renderer.setSize(window.innerWidth, window.innerHeight);
renderer.setPixelRatio(window.devicePixelRatio);
document.getElementById('canvas-container').appendChild(renderer.domElement);

// Controls
const controls = new OrbitControls(camera, renderer.domElement);
controls.enableDamping = true;
controls.autoRotate = true;
controls.autoRotateSpeed = 0.5;

// --- HELPERS ---

// Function to create text labels as sprites (images)
function createTextSprite(text, color = 'white', size = 1) {
    const canvas = document.createElement('canvas');
    const ctx = canvas.getContext('2d');
    canvas.width = 512; 
    canvas.height = 128; // Wide format for text

    ctx.font = 'bold 50px Arial';
    ctx.fillStyle = color;
    ctx.textAlign = 'center';
    ctx.textBaseline = 'middle';
    ctx.fillText(text, 256, 64);

    const texture = new THREE.CanvasTexture(canvas);
    const material = new THREE.SpriteMaterial({ map: texture });
    const sprite = new THREE.Sprite(material);
    
    // maintain aspect ratio
    sprite.scale.set(4 * size, 1 * size, 1); 
    return sprite;
}

// --- OBJECTS ---

// 1. Center Core (You)
const coreGeometry = new THREE.SphereGeometry(1.5, 32, 32);
const coreMaterial = new THREE.MeshBasicMaterial({ color: 0xffffff, wireframe: true });
const core = new THREE.Mesh(coreGeometry, coreMaterial);
scene.add(core);

// Core Label
const nameLabel = createTextSprite("ABIR", "#ffffff", 2);
nameLabel.position.y = 2.5;
scene.add(nameLabel);


// 2. Ventures (Inner Orbit)
const ventureGroup = new THREE.Group();
scene.add(ventureGroup);

ventures.forEach((name, index) => {
    const angle = (index / ventures.length) * Math.PI * 2;
    const radius = 6;
    const x = Math.cos(angle) * radius;
    const z = Math.sin(angle) * radius;

    // Planet Sphere
    const geo = new THREE.SphereGeometry(0.5, 16, 16);
    const mat = new THREE.MeshBasicMaterial({ color: 0xff0055 }); // Red/Pink
    const mesh = new THREE.Mesh(geo, mat);
    mesh.position.set(x, 0, z);
    
    // Label
    const label = createTextSprite(name, "#ff0055", 1.5);
    label.position.set(0, 1, 0); // Above the planet
    mesh.add(label);

    ventureGroup.add(mesh);
});

// 3. Skills (Outer Cloud)
const skillGroup = new THREE.Group();
scene.add(skillGroup);

skills.forEach((skill) => {
    // Random spherical distribution
    const radius = 10 + Math.random() * 5;
    const theta = Math.random() * Math.PI * 2;
    const phi = Math.acos((Math.random() * 2) - 1);

    const x = radius * Math.sin(phi) * Math.cos(theta);
    const y = radius * Math.sin(phi) * Math.sin(theta);
    const z = radius * Math.cos(phi);

    const sprite = createTextSprite(skill, "#00f3ff", 0.8); // Cyan
    sprite.position.set(x, y, z);
    skillGroup.add(sprite);
});

// 4. Starfield Background
const starGeometry = new THREE.BufferGeometry();
const starCount = 2000;
const posArray = new Float32Array(starCount * 3);

for(let i = 0; i < starCount * 3; i++) {
    posArray[i] = (Math.random() - 0.5) * 100; // Spread stars wide
}

starGeometry.setAttribute('position', new THREE.BufferAttribute(posArray, 3));
const starMaterial = new THREE.PointsMaterial({
    size: 0.1,
    color: 0xffffff,
    transparent: true,
    opacity: 0.8
});
const stars = new THREE.Points(starGeometry, starMaterial);
scene.add(stars);


// --- ANIMATION LOOP ---
function animate() {
    requestAnimationFrame(animate);
    
    // Rotations
    core.rotation.y += 0.005;
    core.rotation.x += 0.002;
    
    ventureGroup.rotation.y += 0.01; // Spin ventures orbit
    skillGroup.rotation.y -= 0.002; // Spin skills slowly other way
    stars.rotation.y += 0.0005; // Very slow background shift

    controls.update();
    renderer.render(scene, camera);
}

// Resize Handler
window.addEventListener('resize', () => {
    camera.aspect = window.innerWidth / window.innerHeight;
    camera.updateProjectionMatrix();
    renderer.setSize(window.innerWidth, window.innerHeight);
});

animate();