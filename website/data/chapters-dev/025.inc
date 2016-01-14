<div class="chapsection">
<div class="computer email">
<br/>
<strong>Bug#:</strong> 7392252
<br/>
<strong>Submitted by:</strong> ssrinivanasan
<br/>
<strong>Assigned to:</strong> awolfson
<br/>
<strong>Priority:</strong> P1
<br/>

<br/>
<strong>Title:</strong> Network handler corrupts player inventory
<br/>
<strong>Description:</strong> The Player class’s Inventory accessor returns a pointer instead of scoped reference with a mutex lock (see PlayerNetworkHandler.cpp:2163). If a player can induce concurrent writes, random items will appear. Demo: unit test #12271
<br/>

</div>
<p>
Satish typed details of the defect into the bug tracker, engrossed in his work. He didn’t notice someone entering his office until the door’s latch clicked closed. He looked up from his monitor. The first thing he saw was a large cardboard box. The second was the man holding it. “<em>Danny?</em>”
</p>
<p>
“Hey.” Danny dropped the box. It fell lightly.
</p>
<p>
Satish eyed the box. “What’s that?”
</p>
<p>
“This?” Danny idly kicked it with his toe. “Oh, nothing. It’s empty. I pulled it out of a recycling bin behind Building 34.”
</p>
<p>
Satish shook his head. “How did you get inside the building? Are you just walking around on Microsoft property without a visitor’s badge?”
</p>
<p>
“Do you know what I just discovered a few minutes ago?” Danny said nonchalantly. “If you’re standing outside a doorway carrying a large, heavy-looking box and you act like you’re struggling to grab the door handle, then not only will people <em>not</em> ask you for ID, they’ll even hold the doors open for you.”
</p>
<p>
Satish crossed his arms. “What are you doing here?”
</p>
<p>
Danny sat down in a plastic chair beside the desk. “It appears that our project last night had some unfortunate consequences.”
</p>
<p>
“No shit,” said Satish. “My friend is lying in a hospital bed right now with his head almost caved in.”
</p>
<p>
Danny looked away contritely. “It’s more than that. The drug lord &mdash; Sergey Mukhayev. He found me.”
</p>
<p>
A moment of silence passed. Satish’s face was a complex mixture of shock, contempt, and sympathy.
</p>
<p>
“There’s some kind of Russian mob war,” Danny explained. “Some kingpin kidnapped his daughter. He’s staying at the Medina Gallante hotel. Sergey is demanding that I join him to rescue her.”
</p>
<p>
Satish stared at him, wordless.
</p>
<p>
“I need your help.”
</p>
<p>
After a long pause, Satish replied, “Okay.”
</p>
<p>
“Really?” Danny asked, relieved. “Just like that?”
</p>
<p>
“Yes. Look. I think you’re a clueless dolt, but that doesn’t mean I want you killed. So, yes, I’ll help.”
</p>
<p>
“Thank you,” Danny said humbly.
</p>
<p>
“Now, is your passport valid?”
</p>
<p>
Danny shook his head. “My… What?”
</p>
<p>
“Flights from Sea-Tac to Chhatrapati Shivaji take between twenty to thirty hours. You can get an Indian visa on arrival. I have a brother that can meet you at the airport. He runs an English-language call center in Mumbai. I’ll ask him to set you up with a job. Now, as for buying the plane ticket…”
</p>
<p>
“Whoa, Satish, stop!” Danny interrupted. “I’m not fleeing the country.”
</p>
<p>
“Then why would you come to me?”
</p>
<p>
Danny reached into his pocket and withdrew his data stick. “I got the source code to the Medina Gallante’s integrated data systems. I need your help breaking in. And I need it right now.”
</p>
<p>
Satish blinked in bewilderment. “Danny, this isn’t your fight! Have you lost your mind?”
</p>
<p>
“Quite the contrary. I think I’ve finally begun to find it.”
</p>
<p>
Satish stared at him incredulously.
</p>
<p>
Danny smiled and spoke softly. “You’re right, Satish. I could take you up on fleeing the country. I could abandon my house, my social contacts, my professional ambitions. My budding relationship with Tina. I could just drop it all, right this second, and run. But for what? Survival? At this point in my life, I’m far past the point of considering mere survival a win. I can do better. Reach for something higher.”
</p>
<p>
“And getting involved in a drug war is your idea of ‘something higher’?” said Satish. “No pun intended.”
</p>
<p>
“By itself, no. But helping someone who desperately needs me right now, someone for whom I’m the only hope… That sounds like the right track.”
</p>
<p>
“Are you talking about that Russian guy? You feel like you need to be a hero on behalf of a cocaine dealer?”
</p>
<p>
Danny laughed. “Do you know what cocaine <em>does</em>, Satish? It gives you a feeling of accomplishment. Just straight-up <em>gives</em> it to you. It’s no wonder people love the stuff so much, enough to keep guys like Sergey in business. Who needs to <em>actually</em> pursue dreams or achieve goals, when you can just get the resulting pride and satisfaction directly in powder form?
</p>
<p>
“It’s a fake feeling, of course. You can’t outsmart your own mind. You yourself know perfectly well whether or not you’ve achieved your own goals, because you’re the one that defines those goals in the first place.
</p>
<p>
“There’s something I’ve been starting to understand &mdash; something that may be obvious to a biologist, but I’m still wrapping my head around. Thinking, feeling, wanting, dreaming &mdash; they’re all <em>physical</em> processes. The brain chemical affected by cocaine &mdash; dopamine &mdash; is a real, measurable substance, and it plays a quantifiable role in the brain’s circuitry. When you understand how the components work, it becomes possible to analyze thoughts flowing through a human mind the same way you can analyze instructions flowing through a computer’s CPU. When a neurobiologist talks about what motivates a person, how a person perceives the world and acts on their desires… When you talk about that stuff armed with actual knowledge of how the machinery of the brain operates, you’re not talking philosophy. You’re talking engineering.
</p>
<p>
“I’m a Gen-X dot-com code-monkey. I’ve been programming since my hands could span a keyboard. Computers and I grew up together. I’m among the first-born children of the Information Age. I might not know anything about the mechanics of consciousness, but I do know that if you give me the schematics for an information processing system, I can bend it to my will.
</p>
<p>
“And it’s about time I took those skills and applied them back upon the mind that they arise from.
</p>
<p>
“I have the power to <em>reprogram myself</em>. I can stop being a passive observer of my own life &mdash; constantly lamenting my choices, imagining I had picked different paths, daydreaming what my life would be like in alternate realities. I can <em>own</em> those choices, and <em>live</em> in the reality I’m in. I initially got involved in this whole thing by accident &mdash; Jason’s mis-sent email, the collapse of Tungsten. Those are things that happened <em>to</em> me. I stumbled onto this path by mistake, and followed it because I thought I <em>had</em> to. But now? Now that this is the path I’m on, I will make it <em>mine</em>. I will walk it with <em>intent</em>, with consciousness. I walk it because I <em>choose</em> to.”
</p>
<p>
Danny laid the data stick on Satish’s desk, and slid it forcefully toward him.
</p>
<p>
“Will you help me do that?” Danny said.
</p>
<p>
Satish turned away from Danny to brood. Slowly, his hand moved toward the data stick lying on his desk. He tapped it rhythmically against his desk. Finally, he swung the data stick toward his workstation and plugged it into a USB port.
</p>
<p>
“First thing we can do,” Satish said, opening colorful windows on his computer screen, “is search through all comments in the source code.”
</p>
<p>
Danny grinned.
</p>
<p>
“We’ll look for lines marked, ‘TODO’,” Satish explained. “A lot of times programmers will leave notes for themselves to clean up a bad piece of code. If they’re working toward a deadline and they have to add a new feature quickly, usually they’ll write a sloppy, unreliable version first, figuring they’ll come back and fix it later when they have more time. Which, of course, they never do.”
</p>
<p>
Danny marched over to Satish’s whiteboard and grabbed a dry-erase marker. “Let’s enumerate the system’s external points of contact. There’s the billing subsystem. The VOIP telephone subsystem. The police alarm subsystem…”
</p>
<p>
“This source code includes their unit tests and build verification tests,” Satish said as blocks of text slid across his screen. “A coverage analysis report will show us which parts of their system haven’t been properly tested. …Danny?”
</p>
<p>
“Yeah?”
</p>
<p>
“Pull up a chair,” Satish invited. “This will take a lot of work… But I think it can be done.”
</p>
</div>