import numpy as np
import turtle


class Celestial_body:
    def __init__(self, mass, start_pos, velocity, name, typ, colour, turtle) -> None:
        self.mass = mass
        self.pos = start_pos
        self.velocity = velocity
        self.name = name
        self.typ = typ
        self.colour = colour
        self.turtle = turtle
        self.dt = 500

    def force(self, other_himmellegeme) -> list[float]:
        # bruker newtons gravitasjons lov til å beregne kraft vektor
        distance_vector = np.subtract(self.pos, other_himmellegeme.pos)
        distance = np.sqrt(distance_vector[0]**2 + distance_vector[1]**2)
        force = -6.67*10**-11 * other_himmellegeme.mass * self.mass / distance**3 * distance_vector
        return force 

    def update_pos(self):
        # beregner ny postisjon til himmellegemene
        self.pos = self.pos + self.velocity * self.dt

    def update_speed(self, celestial_bodies) -> None:
        f = np.array([0, 0])
        for celestial_body in celestial_bodies:
            f = f + self.force(celestial_body)
        a = f/self.mass
        self.velocity = self.velocity + a * self.dt


class Planet:
    def __init__(self) -> None:
        self.marker = "circle"
        self.markersize = 10


class Moon:
    def __init__(self) -> None:
        self.marker = "circle"
        self.markersize = 5


class Black_hole:
    def __init__(self) -> None:
        self.marker = "circle"
        self.markersize = 12

    
class Screen:
    def __init__(self) -> None:
        self.window = turtle.Screen()
        self.width = 600
        self.height = 600
        self.focus_object_index = 0
        self.pos_offset = 1e-7
        self.focus_object_index = 0
        self.himmellegemer = [Celestial_body(1.898e27, np.array([0, 0]), np.array([0, 0]), "Jupiter", Planet(), "orange", turtle.Turtle()),
                              Celestial_body(8.931938e22, np.array([4.217e8, 0]), np.array([0, -17334]), "Io", Moon(),
                                        "green", turtle.Turtle()),
                              Celestial_body(4.799844e22, np.array([6.709e8, 0]), np.array([0, -13743]), "Europa",
                                        Moon(), "blue", turtle.Turtle()),
                              Celestial_body(1.4819e23, np.array([1.0704e9, 0]), np.array([0, -10880]), "Ganymede",
                                        Moon(), "red", turtle.Turtle()),
                              Celestial_body(1.075938e23, np.array([1.8827e9, 0]), np.array([0, -8204]), "Callisto",
                                        Moon(), "violet", turtle.Turtle())
                               #Celestial_body(5 * (1.9885*10**30), np.array([0, (1.8827*10**9) * 20]), np.array([0, -300000]),
                                #"Black Hole", Black_hole(), "white", turtle.Turtle())
                              ]
        self.focus_object = self.himmellegemer[self.focus_object_index]

    def scroll_focus_object_up(self) -> None:
        self.focus_object_index += 1
        if self.focus_object_index >= len(self.himmellegemer):
            self.focus_object_index = 0
        self.focus_object = self.himmellegemer[self.focus_object_index]
        self.window.update()

    def scroll_focus_object_down(self) -> None:
        self.focus_object_index -= 1
        if self.focus_object_index < 0:
            self.focus_object_index = len(self.himmellegemer) - 1
        self.focus_object = self.himmellegemer[self.focus_object_index]
        self.window.update()

    def screen_pos(self, himmellegeme) -> tuple[float, float]:
        centerx_offset = 0 - self.focus_object.pos[0] * self.pos_offset 
        centery_offset = 0 - self.focus_object.pos[1] * self.pos_offset 
        return himmellegeme.pos[0] * self.pos_offset + centerx_offset, himmellegeme.pos[1] * self.pos_offset + centery_offset

    def draw(self, himmellegeme) -> None:
        himmellegeme.turtle.up()
        himmellegeme.turtle.setpos(self.screen_pos(himmellegeme)[0], self.screen_pos(himmellegeme)[1])
        himmellegeme.turtle.down()
        self.window.update() 

    def first_draw(self, himmellegeme) -> None:
        himmellegeme.turtle.fillcolor(himmellegeme.colour)
        himmellegeme.turtle.shape(himmellegeme.typ.marker)
        himmellegeme.turtle.up()
        himmellegeme.turtle.goto(self.screen_pos(himmellegeme)[0], self.screen_pos(himmellegeme)[1])
        himmellegeme.turtle.down()
        self.window.update()

    def update(self, celestial_bodies) -> None:
        for celestial_body in celestial_bodies:
            celestial_body.update_pos()
            self.draw(celestial_body)
        for celestial_body in celestial_bodies:
            celestial_body.update_speed([j for j in celestial_bodies if j != celestial_body])


def main() -> None:
    screen = Screen()
    screen.window.setup(screen.width, screen.height)
    screen.window.title('Planetary System')
    screen.window.bgcolor('black')
    screen.window.tracer(0)

    screen.window.listen()
    screen.window.onkeypress(screen.scroll_focus_object_up, "Up")
    screen.window.onkeypress(screen.scroll_focus_object_down, "Down")


    for himmellegeme in screen.himmellegemer:
        screen.first_draw(himmellegeme)

    while True:
        screen.window.update()
        screen.update(screen.himmellegemer)
        
if __name__ == "__main__":
    main()