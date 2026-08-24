"""Record a light spell without triggering a circular import."""
from alchemy.grimoire import light_spell_record

print("=== Kaboom 0 ===")
print("Using grimoire module directly")
spell = light_spell_record("Fantasy", "Earth, wind and fire")
print(f"Testing record light spell: {spell}")
