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
Inside Tungsten’s building, dozens of computers transmitted signals to each other through rapid electromagnetic vibrations. At its heart, the process was no more complex than blinking lights &mdash; but only someone like Danny would think of them as “lights”. Most people would think of them as antennas, and would say they were emitting radio waves. But for Danny, when it came to things like light bulbs or Wi-Fi transceivers or Naval radar systems, the difference was literally in the eye of the beholder. They all worked by sending out photons, and whether the receiving antenna was a thin strand of copper wire inside a computer’s network card or a rhodopsin protein in a rod cell in his retina, the underlying physical principles were invariant.
</p>
<p>
There were pine trees planted beside the office building, arranged in neat woodchip-lined rows. Danny had chosen to park across from these trees intentionally, to stay out of sight. But the pines obscured visible and invisible light alike. 
</p>
<p>
“Move the car over there, where the trees are thinner,” Danny said while pointing. 
</p>
<p>
Pine trees were living things, and their green needles were filled with water. They might as well have been clouds of fog. 
</p>
<p>
The SUV lumbered quietly forward. “The lights are on in their lobby,” Jason said as their angle of view shifted. “And there’s still a car in their parking lot. Is someone in there?”
</p>
<p>
“Not sure,” said Danny. “I think so, but I can’t really see.”
</p>
<p>
Unaided human eyes could see light frequencies ranging from 430 to 790 terahertz, corresponding to colors from red to bluish violet. The waves coming from the Tungsten building had frequencies near 2.45 gigahertz. Human beings who talked about such things, like Danny, didn’t call it “color.” They instead used words like “channel” or “band”. And in place of names like “red”, they used the term “microwave”.
</p>
<p>
“That’s better,” Danny said, focused on his computer screen. “The RSSI from three of the APs just jumped. They’re running WEP over 802.11b. It’s a grossly outdated protocol, just like the OmniVision tech support forum said.”
</p>
<p>
“So you’re in?” asked Jason.
</p>
<p>
“Not yet,” said Danny. “We can see their Wi-Fi network from here, but it’s password protected. Which is exactly why I brought my little friend Cain & Abel here…” 
</p>
<p>
“You mean your friend<em>s</em> Cain and Abel? Plural, right? Who?” Jason asked.
</p>
<p>
“No, Cain & Abel. It’s an application you can download from the web. It’s a, um, ‘password recovery toolkit’,” Danny said with air-quotes and a smirk. “You know, in case you, uh, ever lose the key to your own network. Or… something. So let’s see what it can do here…” He whisked his fingers across his laptop, navigating through an elaborate maze of buttons and drop-down menus. “Passive Scan… Capture to File… Packet Injection ARP Requests… and… Go!”
</p>
<p>
“<em>Now</em> you’re in?” asked Jason.
</p>
<p>
“No! Sheesh! Keep your pants on,” said Danny. “It’ll take a few minutes. Right now, my computer is tricking the machines on the Tungsten network into transmitting tons of data, and looking for patterns in those transmissions. See, Tungsten’s security cameras use an old encryption protocol called Wired-Equivalent Privacy, or WEP. WEP has a subtle mathematical flaw that was discovered in the early 2000s. Every WEP packet gives a small clue about its cryptographic key, so if you capture enough traffic over the air, you can deduce the network password. As we speak, Tungsten’s machines are beaming out sweet, juicy data packets. Just sit back and enjoy the show.”
</p>
<p>
Danny stared out at the Tungsten building, past the trees.
</p>
<p>
If Danny could see into the microwave spectrum, he would see a dazzling symphony of light. The building’s walls would be mostly transparent, with the various computers inside emitting rapid flashes of light, like fireflies in a jar. As the flickering of each computer ceased, a certain designated device &mdash; an access point, or Wi-Fi hotspot in popular parlance &mdash; would light up in response to the darkness. The access point was the choreographer of this luminous dance, its pattern of flashes telling the other devices which one of them should transmit next. One after another, these machines illuminated the night with pure, glowing data.
</p>
<p>
The light was suddenly obscured by Jason’s hand waving and snapping its fingers in front of his face. “Helllooooo, Earth to Danny?”
</p>
<p>
“Huh? What?” Danny jumped to attention.
</p>
<p>
“Distracted by something shiny?”
</p>
<p>
“Yeah,” Danny replied. He looked at his laptop screen. “Sweet, I’ve got plenty of vectors. Now I just hit Analyze… Korek algorithm… Start… and…” He held up his computer, triumphant. “Gentlemen, we can haz password!”
</p>
<p>
With excited commotion, Mike, Moshen, and Satish leaned in to see Danny’s screen. The message “<span class="computer">WEP key found !</span>” showed prominently. They each carefully copied the sequence to their own computers.  “<span class="computer">6430637430725F505F66336C6C61746573…</span>”
</p>
<p>
Mike, sitting behind Danny, announced, “It works. I’m connected.”
</p>
<p>
“Start scanning, Mike,” Danny directed. “Now that we’re behind their firewall, we should be able to reach every machine on their network.”
</p>
<p>
Satish asked, “Do you want to see their camera feeds?”
</p>
<p>
“Yes!” Danny said. “You have video streams?”
</p>
<p>
“I have everything,” said Satish. “I’m doing a promiscuous packet sniff. Look at port 80 on 192.168.2.57. I’m seeing an MPEG-4 stream inside a HTTP session.” Despite years of experience working alongside Indian engineers and normally having no trouble parsing the accents of the subcontinent, Danny had never quite gotten used to the pronunciation of “H” as “hatch”.
</p>
<p>
Upon entering the numbers, Danny’s screen filled with a picture of the driveway in front of the Tungsten building, pixelated and choppy. A narrow ribbon of text ran along the bottom, showing the current date, time, and information about the camera. A rectangle labeled “PTZ” contained icons of arrows and magnifying glasses. Danny clicked on them and found that he could move the camera &mdash; pan, tilt, and zoom. “Niiiii<em>iii</em>ce!” Danny sang.
</p>
<p>
“I’m seeing user activity,” said Satish. “There’s a chat session, and there’s a FireFox browser making requests to stuffonmycat.com. I’m pretty sure someone’s still in the building.”
</p>
<p>
“I’m seeing a bunch more HTTP servers, too, Danny,” said Mike. “Same subnet. Dot-84, dot-91, dot-95…”
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
The screen showed an angled overhead view of a young woman at the reception desk. She wore a black knit cardigan over a simple white button-down shirt. Her unkempt black hair fell below her chin. A small nose stud glinted in the light.
</p>
<p>
What Danny noticed most, though, was her posture and poise &mdash; or rather, her complete lack thereof. She slouched as she tapped away at her keyboard, her shoulders slumped forward. The timing of her keystrokes made it obvious that she was chatting with someone online, feeling no need to appear like she was still working. Her hair was unkempt not because she was going for an artificial messy-chic look, but because it was, in fact, the natural state of her hair after a very long work shift. 
</p>
<p>
Danny smiled. Her hair looked beautiful anyway.
</p>
<p>
Suddenly, the view on Danny’s screen started to move. The camera panned left and down, centering on the girl.
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
“It’s vital reconnaissance work!” Moshen insisted.
</p>
<p>
Jason, somewhat confused, leaned over and looked at Danny’s screen. “Oh,” he said. “That’s Christina. Their office admin.”
</p>
<p>
The video feed zoomed in on her chest. Her shirt and cardigan took up the entire screen.
</p>
<p>
“Dude, stop that!” said Danny, and zoomed the camera out.
</p>
<p>
“No, this is important! We’re here to examine Tungsten’s assets!” said Moshen. As the camera tightened back onto the young woman’s breasts, her torso turned. Her face descended into view, filling the frame. She looked straight into the camera with a perplexed squint, then craned toward the lens.
</p>
<p>
“Shit! Can she see me?” Moshen exclaimed, and rapidly zoomed back out.
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
“Well, we’re on their internal network. Next step is to get onto one of their computers. Right now, we’re like burglars who’ve broken into an apartment building and we’re loitering in the hallways. We haven’t actually gotten into any of the apartments yet. Mike, how’s that network scan coming?”
</p>
<p>
Mike Braun had been making soft grunts of frustration and excitement for the last several minutes. “This place is a goddamned mess,” he replied. “Their network topology makes absolutely no sense. It looks like they’ve got like a dozen network segments, and they seem to be connected completely at random. Normally, a corporate network is organized into groups of related computers, right? Like maybe a subnet for the Finance department, and then inside that, a subnet for Payroll and one for Accounts Receivable. That’s how we’re taught to do it at Bellevue. But this…? This is total chaos. There’s no overall design to it. The sysadmin is either some kind of insane genius, or he just makes up the network structure as he goes along. Like he’s slapping it together out of parts that happen to be lying around.”
</p>
<p>
Danny chuckled a bit. “Not surprising. All of their network administration is handled by this one Roger Tanner kid. You know what it’s like to be a company’s <em>only</em> IT guy?”
</p>
<p>
Mike nodded his large, furry head. “Yeah, most of these machines seem really badly maintained. Some look like they’ve gone months without a patch or an upgrade. Maybe years.”
</p>
<p>
From the back, Satish grumbled in displeasure. “Guys, call me paranoid, but I really don’t think that girl should be at that computer while we do this.”
</p>
<p>
“What’s the big deal?” Danny asked. “You said she’s just chatting and surfing the web.”
</p>
<p>
“If we want to take over her machine,” Satish insisted, “then we don’t want her sitting there watching her screen while her cursor moves all by itself and her files start dragging and dropping.”
</p>
<p>
Mike grunted in agreement. “I think Satish is right, Danny. According to my scan, it doesn’t look like there’s that many Windows boxes on the network. Most of their machines look like highly customized Linux distros. The receptionist’s desktop machine might in fact be the most logical place to start. Which means…”
</p>
<p>
Danny reluctantly nodded. “Which means we have to find some way to make her go away. Damn it. Satish is right.” He looked back down to his laptop, which still showed the girl at her computer. He rubbed his chin and pondered.
</p>
<p>
Gingerly, he pressed the lobby camera’s PTZ buttons. The image panned upward and sideways. Through the glass wall of the Tungsten lobby, embedded in the ceiling of the building’s main corridor, was another sleek black camera dome.
</p>
<p>
“Moshen, see that hallway cam right there?” Danny asked. “Go like this with it…” Danny started pressing buttons with reckless abandon, making the lobby image dance wildly back and forth. “Keep this up for as long as it takes. Come on…”
</p>
<p>
Moshen followed suit with the hallway camera. “I’m dizzy, dude,” he complained. “What’s the point of this?”
</p>
<p>
“We know she can see the cameras spin,” Danny said, still fiddling with the buttons. “We just… Need to get… Her attention…”
</p>
<p>
Suddenly, his entire image jostled violently.
</p>
<p>
“Done!” Danny announced. He took his mouse off of the PTZ buttons. The view came to rest on the receptionist’s face, inches from the lens. His eyes traced the curve of her cheeks, the contours of her lips. He watched as she climbed down from her chair, walked through the lobby doors, and approached the camera that Moshen was driving.
</p>
<p>
“Ohhhh!” Moshen said. He brought up several more camera feeds, and began tapping their PTZ controls.
</p>
<p>
“You got it, Moshen,” said Danny. “Send her on a goose chase all over the building. Just keep her out of that lobby and away from her computer.” With the receptionist thoroughly occupied, he turned to Mike Braun. “Her computer’s exposed, Mike. Ready to launch Metasploit?”
</p>
<p>
Mike stared at his screen in confusion. “Not yet, Danny. I’m seeing something really weird here…”
</p>
<p>
“Weird how?” Danny asked.
</p>
<p>
“Well, it’s really messed up,” he said. “See… Some of those machines in there… I don’t… I’m not sure I’m reading this right… They’re on the Ethernet segment, but…” 
</p>
<p>
“Just say it, Mike,” Danny said.
</p>
<p>
“They’re not using IP,” Mike replied hesitantly.
</p>
<p>
“Heh. Don’t be ridiculous,” said Danny. “Everything uses IP.” He noticed a quizzical expression from Jason. “IP is the digital language of the Internet,” he explained. “Has been for twenty years. Mike, if they’re not using IP, how are they talking to one another?”
</p>
<p>
“It’s…,” said Mike. “I think they’re…”
</p>
<p>
Satish chimed in. “Novell Netware,” he said. “Raw Netware packets directly on the 802.3 frame. I’ve been trying to decode them with WireShark. I thought it was a parsing error this whole time.”
</p>
<p>
“Are you serious?” Danny asked. “Novell hasn’t used that protocol since the mid nineties. Shit, I haven’t heard anybody mention it since I was in college.”
</p>
<p>
Mike said. “Yeah! I’m seeing something called DECnet Routing Protocol. Danny, what is this shit?”
</p>
<p>
Danny shook his head. “It’s ancient…” 
</p>
<p>
On his laptop, he found a camera that Moshen wasn’t spinning at the moment. He brought up a video feed in a room with large steel refrigerators along the walls. One of the refrigerators had a massive metal door with a special lever-like handle. A computer sat next to it, beige with black trim. A small CRT monitor was built into its body, showing a screen of blocky green text. The clunky keyboard was two inches thick and looked heavy enough to use as a bludgeoning weapon. 
</p>
<p>
Danny recognized it. It was a relic. An honest-to-God DEC VT100 terminal. It wasn’t even a real computer. Digital Equipment Corporation, or DEC, discontinued those machines when Danny was in junior high. 
</p>
<p>
DEC itself, even for Danny, was barely even a memory anymore. After forty years as a multi-billion-dollar industry leader, DEC finally went defunct in 1998, unable to compete against the low-cost Intel x86-based Windows PCs flooding the market. DEC was bought out by Compaq, who manufactured the very machines that had caused DEC’s demise. Compaq, in turn, was bought out by Hewlett-Packard in 2002. There was a time when DEC terminals were as common as telephones &mdash; yet Danny realized that, today, even the most computer-savvy twentysomethings had never even heard of them.
</p>
<p>
He switched to a camera in the cramped warehouse-like storeroom. In the light of the weak yellow lamps, Danny could make out computers scattered among the rest of the unused equipment. There was the curvy purple case of an SGI O2+ workstation. There was a black NeXT cube. There was equipment by Solaris. By Sun Microsystems. By Amiga. By Tandy.
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
His first job in college was porting one of the University’s data entry systems from a DEC PDP-11 to IBM’s OS/2. He laughed at the poor engineering and primitive design of the original PDP-based software &mdash; it wasn’t until many years later that he realized that the engineer who had built <em>that</em> system had needed, in turn, to keep it compatible with something even older. Danny knew everything back then. There was no technical challenge that wouldn’t crumble under the might of his awesome intellect. He was eighteen years old.
</p>
<p>
IBM discontinued OS/2 in 2001.
</p>
<p>
His master’s thesis was on techniques for transistor placement to optimize thermal dissipation in 3D VLSI layout. His education was funded by a grant from Cray Computer Corporation. Danny’s research was supposed to have been a key part of the company’s efforts to keep supercomputer architectures competitive against new-fangled “massively parallel” systems. Once, he even had the profound honor of attending a dinner with the legendary Seymour Cray himself. Even at the age of 70, that man’s mind was unstoppable. Danny idolized him. Danny was twenty-two years old.
</p>
<p>
“Danny?” Jason said softly from the driver’s seat of the Lincoln Navigator.
</p>
<p>
“What?” Danny croaked out, his voice scraping over a lump in his throat.
</p>
<p>
Seymour Cray died in a car accident the following year. Cray Computer Corporation went bankrupt in 1995. A boom in massive parallelization technology rendered the supercomputer obsolete.
</p>
<p>
He slammed his laptop shut. “Fuck,” Danny exhaled sharply.
</p>
<p>
“Danny, are you okay?” Jason said.
</p>
<p>
“Yeah, I’m f&mdash;,” Danny began to say, but felt his voice crack. He was crying. 
</p>
<p>
The SUV was silent. He could feel everyone looking at him. He didn’t dare turn his face and let them see his wet, red eyes. “I’m fine,” he mumbled, but he knew he wasn’t fooling anybody. He swallowed hard, yanked at the door handle, and hopped out of the car, slamming the door behind him. He sat down on the pavement against the tire, set his laptop down by his feet, and buried his face in his hands.
</p>
<p>
Jason exited the SUV and came around. “You alright?” he asked, sitting down beside him.
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
“What’s going on with you, Danny?” Jason’s tone was professional but kind.
</p>
<p>
“Six years at one dead company. Six years at another. And another. And another…” Danny stared away emptily. “I fucking hate the computer industry. It’s such a goddamned waste of life. I’ve been doing this for over twenty years, and every damn thing I’ve ever built just gets swept away by the next great wave. My resume reads like the dot-com obituaries. They all start out as brilliant ideas and then become obsolete and useless in the time it takes to put those ideas into action.”
</p>
<p>
Jason thought for a few moments before replying. “You remember what I said, Danny, when I saw you holding that invention of yours back at the club? You love your work. I know you do.”
</p>
<p>
“I do, Jason. I love it so much it’s fucking heartbreaking. Do you know how much it hurts to love something that dies so quickly? You learn some amazing complex system, and then bam! Obsolete overnight. Do you have any idea how much outdated technical shit is in my head? I can rattle off every opcode in the Motorola 68K instruction set. I know the full pin-out structure for the Intel 80286 CPU. I know a thousand things that, at their time, were cutting-edge. I was fucking awesome. And now what? Time has left them in the dust, and all that shit is still in my head, like the abandoned ruins of some ancient civilization. All that skill, that hard-won knowledge… it’s useless. Completely, utterly fucking useless.” He gulped painfully. “Just like me.”
</p>
<p>
Jason stood up beside him and reached his hand down toward Danny. “Listen. I’m not sure exactly what triggered this, but if you really take pride in your work, then… Well, you’re at work this very minute, remember? Stop sulking. You’re on the clock. You’ve got a job to do.”
</p>
<p>
Danny breathed slowly, as though the broth of self-pity that boiled in his gut could be chilled by drinking in the cool, moist air. “You’re right.” With a deep sigh, Danny took Jason’s hand and pulled himself up to his feet. 
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
Several cars had already driven by. What made Danny and Jason notice this one, besides its stylishness and the unusual, eerily quiet way it moved, was that it slowed down and turned into the Tungsten parking lot.
</p>
<p>
Through the pine trees, they could see the Roadster stop just in front of Tungsten’s entrance. Two male figures emerged, clad in dark jackets and leather gloves. They stood outside talking in the light pouring from the lobby.
</p>
<p>
“Danny! Jason!” Mike’s voice came from the SUV. “Are you watching the two guys?”
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
“Look at the parking lot camera,” said Mike.
</p>
<p>
Danny re-opened his laptop and brought up the video feed.
</p>
<p>
The two men stood in front of their electric sports car, talking. They had athletic, muscular bodies, and hard faces that looked like they were comfortable and familiar with danger. They had slim cellphones with Bluetooth headsets, which they set up and put into their ears.
</p>
<p>
And they had guns.
</p>
<p>
One carried a thin semiautomatic handgun; the other, a short silver revolver with a disproportionately large opening. The men held the firearms nonchalantly, casually gesturing with them as they talked. 
</p>
<p>
With a nod, the one with the revolver tucked his gun into a jacket pocket. He opened the Roadster’s door and retrieved an object from inside. Danny zoomed in on the man’s hands. It was a woman’s handbag &mdash; a Hello Kitty purse. The man pulled a keycard out of it, threw the purse back into the car, and walked out of frame. Danny zoomed back out, following the man’s movement to the entrance of Tungsten’s headquarters. A green light popped on above the door’s keycard reader. The man handed the keycard to his partner and entered the building.
</p>
<p>
The other man remained out front, standing beside the front doors. He pulled back the slide on his weapon and deftly screwed a long black silencer onto the end of the barrel. With the silencer firmly installed, he pushed a clip into the gun’s handgrip and released the slide, causing it to snap forward. He took off his jacket and draped it over his hand, concealing the weapon. Crooking his arm casually at his side, he leaned against the wall as though idly waiting for someone.
</p>
<p>
The man with the small revolver strode confidently through the lobby. He opened the interior door and proceeded into the unlit hallway beyond.
</p>
<p>
Danny quickly checked the lobby’s camera feed. The receptionist’s iPhone sat charging on her desk. “Guys. The girl. Christina,” Danny reminded them. “Moshen, where is she?” 
</p>
<p>
Moshen replied, “I had her chasing spinnies into the main office.”
</p>
<p>
Danny punched the corresponding URL into his browser. The video feed showed an office bullpen. The lights were off for the night, but the room was illuminated by screensavers and the power lights of office equipment. The desks were mostly messes of computers, papers, and laboratory apparatuses. White lab coats hung from the backs of curvy ergonomic chairs. Whiteboards filled with diagrams and equations lined the walls.
</p>
<p>
Christina looked up into the now-still camera, her hands on her hips and her lips pursed to one side.
</p>
<p>
In the darkened hallway beyond the bullpen, a shadow moved.
</p>
<p>
Danny realized that, whatever his own personal problems might be, the girl on the screen was about to have much more pressing issues.
</p>
<p>

</div>