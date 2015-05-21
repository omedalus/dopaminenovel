<div class="chapsection">
<p>
<span class="caplead">Danny’s face was lit from afar</span> by invisible light, in a shade of red too deep to be seen by the human eye. He and the other four men sat in Jason’s black Lincoln Navigator SUV parked across the street from the broad suburban office building that housed Tungsten Medical Technologies.
</p>
<p>
“Any luck?” asked Jason from behind the wheel.
</p>
<p>
Danny sat in the passenger’s seat, staring at his laptop. His Claymore tote bag, filled with the pieces of his priceless contraption, lay at his feet. “Some. I’ve got twenty access points in range, but I can’t tell which ones are on the Tungsten network.”
</p>
<p>
Inside Tungsten’s building, dozens of computers transmitted signals to each other through rapid electromagnetic vibrations. At its heart, the process was no more complex than blinking lights &mdash; but only someone like Danny would think of them as “lights”. Most people would think of them as antennas, and would say they were emitting radio waves. But for Danny, when it came to things like light bulbs or WiFi transceivers or Naval radar systems, the difference was literally in the eye of the beholder. They all worked by sending out photons, and whether the receiving antenna was a thin strand of copper wire inside a computer’s network card or a rhodopsin protein in a rod cell in his retina, the underlying physical principles were invariant.
</p>
<p>
Danny surveyed the office building. There were trees planted beside it &mdash; pines arranged by professional landscapers into neat woodchip-lined rows. Danny had chosen to park near these trees intentionally, to stay out of sight. But the trees obscured visible and invisible light alike. 
</p>
<p>
“Move the car over there, where the trees are thinner,” Danny said while pointing. 
</p>
<p>
Pine trees were living things, and their green needles were filled with water. As each electromagnetic wave passed by, the polarized water molecules would bounce and jostle, sapping the wave’s energy. The trees might as well have been clouds of fog. 
</p>
<p>
Jason nodded and complied. The SUV lumbered quietly forward. “The lights are on in their lobby,” he said, as their angle of view shifted. “And there’s still a car in their parking lot. Is someone in there?”
</p>
<p>
“Not sure,” said Danny. “I think so, but I can’t really see.”
</p>
<p>
Unaided human eyes could see light frequencies ranging from 400 to 790 terahertz, corresponding to colors from red to bluish violet. The lights coming from the Tungsten building had frequencies near 2.45 gigahertz. Human beings who talked about such things, like Danny, didn’t call it “color.” They instead used words like “channel” or “band”. And in place of names like “red”, they used the term “microwave”.
</p>
<p>
“That’s better,” Danny said, focused on his computer screen. “The RSSI from three of the APs just jumped. They’re running WEP over 802.11b. It’s a grossly outdated protocol, just like the message board said. I think these are the droids we’re looking for.”
</p>
<p>
“So you’re in?” asked Jason.
</p>
<p>
“Not yet,” said Danny. “We can receive their transmissions from here, but they’re encrypted. We still have to crack them. Which is exactly why I brought my little friend Cain & Abel here…” 
</p>
<p>
“You mean your friends Cain and Abel? Plural, right? Who?” Jason asked, confused.
</p>
<p>
“No, Cain & Abel,” Danny corrected. “It’s an application written by an Italian hacker named Massimiliano Montoro. It’s a, um, ‘password recovery toolkit’,” Danny said with air-quotes and a smirk. “You know, in case you, uh, ever lose the key to your own network. Or… something. So let’s see what it can do here…” He whisked his fingers across his laptop, navigating through an elaborate maze of buttons and drop-down menus. “Passive Scan… Capture to File… Packet Injection ARP Requests… and… Go!”
</p>
<p>
“<em>Now</em> you’re in?” asked Jason.
</p>
<p>
“No! Sheesh,” said Danny. “Keep your pants on. It’ll take a few minutes. Right now my computer is tricking the machines on the Tungsten network into transmitting tons of data, and looking for patterns in those transmissions. See, Tungsten’s security cameras use an old WiFi protocol called Wired-Equivalent Privacy, or WEP. WEP has a subtle mathematical flaw that was discovered in the early 2000s. Every WEP packet gives a small clue about its cryptographic key, so if you capture enough traffic over the air, you can deduce the network password. As we speak, Tungsten’s machines are beaming out sweet, juicy packets. Just sit back and enjoy the show.”
</p>
<p>
Danny stared out at the Tungsten building, past the trees.
</p>
<p>
If Danny could see into the microwave spectrum, he would see a dazzling symphony of light. The building’s walls would be mostly transparent, with the various computers inside emitting rapid flashes of light like fireflies in a jar. As the flickering of each computer ceased, a certain designated device &mdash; an access point, or WiFi hotspot in popular parlance &mdash; would light up in response to the darkness. The access point was the choreographer of this luminous dance, its pattern of flashes telling the other devices which one of them should transmit next. One after another, these machines illuminated the night with pure, glowing data.
</p>
<p>
Danny couldn’t see it with his eyes, but he could visualize it clearly. It was beautiful.
</p>
<p>
The light was suddenly obscured by Jason’s hand waving and snapping its fingers in front of his face. “Helllooooo, Earth to Danny?”
</p>
<p>
“Huh? What?” Danny jumped to attention.
</p>
<p>
“Distracted by something shiny again?”
</p>
<p>
“Yeah,” Danny replied. He looked at his laptop screen. “Sweet, I’ve got plenty of vectors. Now I just hit Analyze… Korek algorithm… Start… and…” He held up his computer, triumphant. “Gentlemen, we can haz password!”
</p>
<p>
With excited commotion, Mike, Moshen, and Satish leaned in to see Danny’s screen. The message “<span class="computer">WEP key found !</span>” showed prominently in a window. They each carefully copied the sequence of hexadecimal digits to their own computers.  “<span class="computer">6430637430725F505F66336C6C61746573…</span>”
</p>
<p>
Mike, sitting right behind Danny, announced, “It works. I’m connected.”
</p>
<p>
“Start scanning, Mike,” Danny directed. “Now that we’re behind their firewall, we should be able to reach every machine on their network.”
</p>
<p>
Satish entered the conversation. “Do you want to see their camera feeds?”
</p>
<p>
“Yes!” Danny said. “You have their video streams?”
</p>
<p>
“I have everything,” said Satish. “I’m doing a promiscuous packet sniff. I’m seeing an MPEG-4 stream inside a HTTP session. Look at port 80 on 192.168.2.57.”
</p>
<p>
Danny entered the numbers. His screen filled with a video feed of the driveway just in front of the Tungsten building, pixelated and choppy with blocky digital glitches. A narrow ribbon of text ran along the bottom, showing the current date, time, and information about the camera. A rectangle labeled “PTZ” contained buttons with icons of arrows and magnifying glasses. Danny played with them and found that he could move the camera &mdash; pan, tilt, and zoom.
</p>
<p>
“Niiiii<em>iii</em>ce!” Danny sang.
</p>
<p>
“I’m also seeing some web-browsing activity,” said Satish. “There’s a machine on the subnet making requests to stuffonmycat.com with a FireFox browser. I’m pretty sure someone’s still in the building.”
</p>
<p>
“I’m seeing a bunch of HTTP servers, too, Danny,” said Mike. “Besides the one Satish found. Same subnet. Dot-84, dot-91, dot-95…”
</p>
<p>
Danny brought up each one. They were all video feeds from security cameras.  He saw office hallways. He saw conference rooms and cubicles with whiteboards covered with chemical formulas. He saw laboratories full of beakers, refrigerators, centrifuges, and measurement instruments. He saw a large warehouse-like storage room filled with scientific and medical equipment. 
</p>
<p>
He saw the reception area. Somebody was there.
</p>
<p>
“Guys. Check out dot-177,” said Danny.
</p>
<p>
The screen showed an angled overhead view of a young woman at the reception desk. She wore a black knit cardigan over a simple white button-down shirt. Her unkempt black hair fell just below her chin. A small nose stud glinted in the light.
</p>
<p>
What Danny noticed most, though, was her posture and poise &mdash; or rather, her complete lack thereof. She slouched as she tapped away at her keyboard, her shoulders slumped and her spine crooked. The timing of her keystrokes made it obvious that she was chatting with someone online, feeling no need to appear like she was still working. Her hair was unkempt not because she was trying to artificially make it look naturally beautiful, but because it was, in fact, the natural state of her hair after a very long work shift. 
</p>
<p>
Danny smiled. Her hair looked beautiful anyway.
</p>
<p>
Suddenly, the view on Danny’s screen started to move.
</p>
<p>
The camera panned left, then down, centering on the girl.
</p>
<p>
“Hey! Who’s doing that?” barked Danny.
</p>
<p>
“Doing whaaaaat?” Moshen said from the back of the car.
</p>
<p>
“Quit playing with the PTZ buttons!” said Danny. 
</p>
<p>
“What? I’m just trying to get a better look at Tungsten’s personnel here. It’s vital reconnaissance work!”
</p>
<p>
Jason, somewhat confused, leaned over and looked at Danny’s screen. “Oh,” he said. “That’s Christina. Their office admin.”
</p>
<p>
The video feed zoomed in on the girl’s chest. Her shirt and cardigan took up the entire screen.
</p>
<p>
“Helllooooo Nurse!” said Moshen.
</p>
<p>
“Dude, stop that!” said Danny, and zoomed the camera out.
</p>
<p>
“No, this is important! We’re here to examine Tungsten’s assets!” said Moshen. As the camera tightened back onto the young woman’s breasts, her torso turned, and her face descended into view, filling the frame. She looked straight into the camera with a perplexed expression. Squinting with suspicion, she tilted her head slightly and craned her face toward the lens.
</p>
<p>
“Shit! Can she see me?” Moshen exclaimed.
</p>
<p>
She self-consciously adjusted her cardigan and turned back to her computer.
</p>
<p>
“Quit dicking around!” Danny commanded.
</p>
<p>
“Okay okay, sorry,” said Moshen. “What’s next?”
</p>
<p>
“Well, we’re on their internal network. Next step is to get onto one of their computers. Right now we’re like a burglar who’s broken into an apartment building and is loitering in the hallways. We haven’t actually gotten into any of the apartments yet. Mike, how’s that network scan coming?”
</p>
<p>
Mike Braun had been periodically making soft grunts of frustration and excitement for the last several minutes. “This place is a goddamned mess,” he replied.
</p>
<p>
“What do you mean?” said Danny.
</p>
<p>
“Well, their network topology makes absolutely no sense,” said Mike. “It looks like they’ve got like a dozen different network segments, and they seem to be connected completely at random. Normally, a corporate network is organized into groups of related computers, right? Like maybe a subnet for the Finance department, and then inside that, subnets for Payroll and for Accounts Receivable. That’s how we’re taught to do it at Bellevue. But this…? This is total chaos. There’s no overall design to it. The sysadmin is either some kind of insane genius, or he just makes up the network structure as he goes along. Like he’s slapping it together out of parts that happen to be lying around.”
</p>
<p>
Danny chuckled a bit. “Not surprising. All of their network administration is being handled by this Roger Tanner guy. He’s probably constantly pressed for time. It always seems easier and quicker to build things ad-hoc than to design systems with long-term operation in mind.”
</p>
<p>
Mike nodded his large, furry head. “Yeah, most of these machines seem really badly maintained. Some look like they’ve gone months without a patch or an upgrade. They’re probably riddled with security holes.”
</p>
<p>
“Perfect,” said Danny. “Metasploit will make quick work of them.”
</p>
<p>
“Well, there’s one other thing, Danny,” said Mike hesitantly. “It’s really messed up. See… Some of those machines in there… I don’t… I’m not sure I’m reading this right… They’re on the Ethernet segment, but…” 
</p>
<p>
“Just say it, Mike,” Danny said.
</p>
<p>
“They’re not using IP,” Mike replied hesitantly.
</p>
<p>
“Heh. Don’t be ridiculous,” said Danny. “Everything uses IP.” He noticed a quizzical expression on Jason’s face. “IP is the digital language of the Internet,” he explained. “Has been for twenty years. Mike, if they’re not using IP, how are they talking to one another?”
</p>
<p>
“It’s… I…,” said Mike. “I think they’re…”
</p>
<p>
Satish’s voice chimed in. “Novell Netware,” he said. “Raw Netware packets directly on the 802.3 frame.”
</p>
<p>
“Are you serious?” asked Danny
</p>
<p>
“I’ve been trying to decode them,” said Satish. “WireShark’s been telling me they’re Netware. I thought it was a parsing error this whole time.”
</p>
<p>
Danny felt bewildered. “Novell hasn’t used that protocol since the mid nineties. Shit, I haven’t heard anybody mention it since I was in college.”
</p>
<p>
Mike said. “Yeah! I’m seeing something called DECnet Routing Protocol. Danny, what is this shit?”
</p>
<p>
Danny shook his head. “It’s ancient…” He turned his attention back to his laptop, which still showed the lobby camera feed. Christina wasn’t at her desk anymore. His interest now wasn’t in her, but in the computers in the building.
</p>
<p>
He brought up a camera in a room with large steel refrigerators along the walls. One of the refrigerators had a massive metal door with a special lever-like handle. A computer sat on a desk next to it, beige with black trim. A small CRT monitor was built into its body, showing a screen of blocky green text. The clunky keyboard was two inches thick and looked heavy enough to use as a bludgeoning weapon. 
</p>
<p>
Danny recognized it. It was a relic. An honest-to-God DEC VT100 terminal. It wasn’t even a real computer. Digital Equipment Corporation, or DEC, discontinued those machines when Danny was in junior high. 
</p>
<p>
DEC itself was barely even a memory anymore. After forty years as a multi-billion-dollar trendsetter for every aspect of the computer industry, DEC finally went defunct in 1998, unable to compete against the low-cost Intel x86-based Windows PCs flooding the market. DEC was bought out by Compaq, who manufactured the very machines that had caused DEC’s demise. Compaq, in turn, was bought out by Hewlett-Packard in 2002.
</p>
<p>
He switched to a few of the cameras in the cramped warehouse-like storeroom. In the light of the weak yellow lamps, Danny could make out a few computers scattered among the rest of the unused equipment. He saw the curvy purple case of an SGI O2+ workstation. He saw a black NeXT cube. He saw equipment by Solaris. By Sun Microsystems. By Amiga. By Tandy.
</p>
<p>
He felt dizzy. It was all, as he said, ancient.
</p>
<p>
Ancient. Yet so familiar. So painfully, intimately familiar.
</p>
<p>
The first program Danny ever wrote was a BASIC script on a brand-new, cutting-edge Tandy TRS-80 that his dad brought home from Radio Shack and hooked to their big, knobby family TV. The program filled the rounded glass screen with “DANNY”, scrolling in an endless loop. He wrote it all by himself. He was seven years old.
</p>
<p>
Tandy went defunct in 2000.
</p>
<p>
His first job in college was porting one of the University’s data entry systems from a DEC PDP-11 to IBM’s OS/2. He laughed at the poor engineering and primitive design of the original PDP-based software &mdash; he didn’t realize that the engineer who had built <em>that</em> system in turn, needed to keep it compatible with something even older. Danny knew everything back then. He was the smartest, most talented guy alive. There was no technical challenge on Earth that wouldn’t crumble under the might of his intellect. He was eighteen years old.
</p>
<p>
IBM discontinued OS/2 in 2001.
</p>
<p>
His master’s thesis was on techniques for transistor placement to optimize thermal dissipation in 3D VLSI layout. His education was funded by a grant from Cray Computer Corporation. Danny’s research was supposed to have been a key part of the company’s efforts to keep supercomputer architectures competitive against new-fangled “massively parallel” systems. Once, he even had the profound honor of attending a dinner with the legendary Seymour Cray himself. Even at the age of 70, that man’s mind was unstoppable. Danny idolized him. Danny was twenty-two years old.
</p>
<p>
Seymour Cray died in a car accident the following year. Cray Computer Corporation went bankrupt in 1995. A boom in massive parallelization technology rendered the supercomputer obsolete.
</p>
<p>
He slammed his laptop shut. “Fuck,” Danny exhaled sharply.
</p>
<p>
“Danny?” Jason said softly from the driver’s seat of the Lincoln Navigator.
</p>
<p>
“What?” Danny croaked out.
</p>
<p>
“Danny, are you okay?” Jason said.
</p>
<p>
“Yeah, I’m f&mdash;,” Danny began to say, but felt his voice crack. He was crying. 
</p>
<p>
The SUV was silent. He could feel everyone looking at him. He didn’t dare turn his face and let them see his wet, red eyes. “I’m fine,” he mumbled, but he knew he didn’t sound convincing. He swallowed hard, and said, “I need some air.” 
</p>
<p>
He yanked at the door handle and hopped out of the SUV, slamming the door behind him. He sat down on the pavement against the SUV’s tire, set his laptop down by his feet, and buried his face in his hands.
</p>
<p>
Jason exited the SUV and came around.
</p>
<p>
“You alright?” Jason asked, sitting down beside him.
</p>
<p>
Danny sighed. He poked at his laptop with his foot. “I hate these things,” he said.
</p>
<p>
“Laptops?”
</p>
<p>
“Computers. Cellphones. Kindles. iPods. iPads. Androids. I fucking hate it all.”
</p>
<p>
“Aww, c’mon. No you don’t. How can you hate the iPad?” Jason said lightly. “It’s all sleek and shiny!”
</p>
<p>
“I mean working in the computer industry. It’s such a goddamned waste of life.” He stared away emptily. “I’ve been doing this for over twenty years, and every damn thing I’ve ever built just gets swept away by the next great wave. My resume reads like dot-com obituaries. They all start out as brilliant ideas and then become obsolete and useless in the time it takes to put those ideas into action.”
</p>
<p>
Jason said probingly, “But, Danny, you love your work…”
</p>
<p>
“I do, Jason. I love it so much it’s fucking heartbreaking. Do you know much it hurts to love something that dies so quickly? You learn some amazing complex system, and then bam! Obsolete overnight. Do you have any idea how much outdated technical shit is in my head? I can rattle off every opcode in the Motorola 68K instruction set. I know the full pin-out structure for the Intel 80286 CPU. I know a thousand things that, at their time, were cutting-edge and I learned them cold and I was fucking awesome. And now what? Now time has left them in the dust, and all that shit is still in my head, like the abandoned ruins of some ancient civilization. All that skill, all that hard-won knowledge… it’s useless. Completely, utterly fucking useless.” He gulped painfully. “And so am I.”
</p>
<p>
“Listen, Danny. I’m not sure exactly what triggered this, but one thing I know is that you take pride in your work. Well, you’re at work at this very minute, Danny. Stop sulking. You’re on the clock. You’ve got a job to do.”
</p>
<p>
Danny breathed slowly, as though the broth of self-pity that boiled in his mind could be chilled by drinking in the cool, moist air. “You’re right. Just give me a minute.”
</p>
<p>
With a deep sigh, Danny slowly pushed himself away from the SUV and stood up. 
</p>
<p>
The stillness of the night was broken by the soft sound of tires on pavement. 
</p>
<p>
A sound that came, oddly, with no corresponding engine rumble.
</p>
<p>
A gleaming white Tesla Roadster made its way up the street adjoining the office complexes.
</p>
<p>
Several cars had already driven by. What made Danny and Jason notice this one, besides its stylishness and the unusual, eerily quiet way it moved, was that it slowed down and turned in to the Tungsten parking lot.
</p>
<p>
Through the pine trees, they could see the Roadster pull to a stop just in front of Tungsten’s entrance. Two male figures emerged. They stood outside talking in the light pouring from the lobby.
</p>
<p>
“Danny! Jason!” Mike’s voice came from the SUV. “Are you watching the two guys in front of the building?”
</p>
<p>
“Yeah, we can see them from here,” said Danny.
</p>
<p>
“For fuck’s sakes, <em>get down</em>!” said Mike.
</p>
<p>
Danny and Jason hid behind the black Navigator. “What’s going on?” asked Danny.
</p>
<p>
“Look at dot-212,” said Mike. “It’s a parking lot camera.”
</p>
<p>
Danny re-opened his laptop and brought up the video feed.
</p>
<p>
The two men in dark jackets and black leather gloves stood in front of their electric sports car, talking. They had athletic, muscular bodies, and hard faces that looked like they were comfortable and familiar with danger. They had slim cellphones with Bluetooth wireless headsets, which they set up and put into their ears.
</p>
<p>
And they had guns.
</p>
<p>
One carried a thin black semiautomatic handgun; the other, a short silver revolver with a disproportionately large opening. The men held the firearms in their hands nonchalantly, casually gesturing with them as they talked. 
</p>
<p>
With a nod, the one with the revolver tucked his gun into a jacket pocket. He opened the Roadster’s door and retrieved an object from inside. Danny zoomed in on the man’s hands. It was a woman’s handbag &mdash; a Hello Kitty purse. The man pulled a keycard out of it, threw the purse back into the car, and walked out of frame. Danny zoomed back out, following the man’s movement to the entrance of the Tungsten headquarters. A green light popped on above the door’s keycard reader. The man handed the keycard to his partner and entered the building.
</p>
<p>
The other man remained out front, standing beside the front doors. He pulled back the slide on his weapon and deftly screwed a long black silencer onto the end of the barrel. With the silencer firmly installed, he pushed a clip into the gun’s handgrip and released the slide, causing it to snap forward. He took off his jacket and draped it over his hand, concealing the weapon. Crooking his arm casually at his side, he leaned against the wall as though idly waiting for someone.
</p>
<p>
The man with the small revolver strode confidently through the lobby. He opened the interior door and proceeded into the unlit hallway beyond.
</p>
<p>
Danny quickly checked the lobby’s camera feed. The receptionist was gone; her iPhone sat charging on her desk. “Guys. The girl. Christina,” Danny reminded them. “Does anyone see where she is?” 
</p>
<p>
Mike replied, “Check the main office camera.”
</p>
<p>
Danny punched the corresponding URL into his browser. The video feed showed an office bullpen. The lights were off for the night, but the room was still illuminated by screensavers and the power lights of office equipment. The desks were mostly messes of computers, papers, and laboratory apparatuses. White lab coats hung from the backs of curvy ergonomic chairs. Whiteboards filled with diagrams and equations lined the walls.
</p>
<p>
Christina’s head, with her dark mass of hair, poked out above a computer monitor. She stooped over a desk, digging through its drawers.
</p>
<p>
In the darkened hallway beyond the bullpen, a shadow moved.
</p>
<p>
Danny realized that, whatever his own personal problems might be, the girl on the screen was about to have much more pressing issues.
</p>
<p>

</div>